#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <assert.h>
#include "md5.h"

#define __MSG_QUEUE_GROUP_NODES (10)
#define __MSG_QUEUE_GROUP_HASHES_PER_NODE (100)
#define __MSG_QUEUE_GROUP_HASHES ( __MSG_QUEUE_GROUP_NODES * __MSG_QUEUE_GROUP_HASHES_PER_NODE )
#define __DIGEST_TO_HASH(digest, index) (\
    ( (digest)[3 + (index)*4] << 24 ) | \
    ( (digest)[2 + (index)*4] << 16 ) | \
    ( (digest)[1 + (index)*4] << 8  ) | \
    ( (digest)[0 + (index)*4] ) \
)
                                        

typedef struct msgQueueGroupHashes
{
    int nodeIndex;
    unsigned int nodeHash;
} MsgQueueGroupHashesT;

static MsgQueueGroupHashesT msgQueueGroupHashes[__MSG_QUEUE_GROUP_HASHES ];

static void computeMd5(unsigned char *key, int keylen, unsigned char digest[16])
{
    md5_state_t md5;
    md5_init(&md5);
    md5_append(&md5, key, keylen);
    md5_finish(&md5, digest);
}

static int msgQueueGroupSortCmp(const void *a, const void *b)
{
    const MsgQueueGroupHashesT *hash1 = a;
    const MsgQueueGroupHashesT *hash2 = b;
    if(hash1->nodeHash < hash2->nodeHash) return -1;
    if(hash1->nodeHash > hash2->nodeHash) return 1;
    return 0;
}

/*
 * Create msg queue group continnum per node or group member
 */
static int createMsgQueueGroupHashes(int nodes, int hashesPerNode, MsgQueueGroupHashesT *nodeHashes)
{
    int i, j;
    int hashes = nodes * hashesPerNode;
    int scaledHashesPerNode = 0;
    int hashIndex = 0;
    int err = -1;

    if(hashes <= 0 || hashesPerNode < 4) goto out;

    /*
     * 4 keys per md5 digest of 16 bytes
     */
    scaledHashesPerNode = hashesPerNode >> 2;
    for(i = 0; i < nodes; ++i)
    {
        for(j = 0; j < scaledHashesPerNode; ++j)
        {
            char *key = NULL;
            unsigned char md5Digest[16];
            int h;
            asprintf(&key, "%d-%d", i, j);
            computeMd5((unsigned char*)key, strlen(key), md5Digest);
            free(key);
            for(h = 0; h < 4; ++h)
            {
                /*  
                 * hashIndex = i*hashesPerNode + j*4 + h    
                 */
                nodeHashes[hashIndex].nodeHash = __DIGEST_TO_HASH(md5Digest, h);
                nodeHashes[hashIndex].nodeIndex = i;
                ++hashIndex;
            }
        }
    }
    assert(hashIndex <= hashes);
    printf("Total hashes for [%d] nodes = [%d]\n", nodes, hashIndex);
    qsort(nodeHashes, hashIndex, sizeof(*nodeHashes), msgQueueGroupSortCmp);
    err = 0;

    out:
    return err;
}

static unsigned int msgQueueGroupKeyToHash(unsigned char *key, int keylen)
{
    unsigned char digest[16];
    computeMd5(key, keylen, digest);
    return __DIGEST_TO_HASH(digest, 0);
}

/*  
 * Given a key, find an index or node with a bisectLeft routine such that
 * returned index hash >= key hash. 0 < keyHash <= indexhash
 */
static MsgQueueGroupHashesT *msgQueueGroupGetNode(unsigned char *key, int keylen,
                                                  MsgQueueGroupHashesT *nodeHashes, int numHashes)
{
    unsigned int hash = msgQueueGroupKeyToHash(key, keylen);
    int left = 0;
    int right = numHashes - 1;
    int mid = 0, mid2 = 0;
    int fallbackIndex = 0; /* fall to the first index when out of range*/
    //    printf("Hash for key [%.*s] = [%#x]\n", keylen, key, hash);
    while(left <= right)
    {
        mid = (left + right) >> 1;
        mid2 = (mid > 0) ? mid - 1 : 0;

        if(mid == mid2)
            return &nodeHashes[fallbackIndex];

        if(hash <= nodeHashes[mid].nodeHash)
        {
            if(hash == nodeHashes[mid].nodeHash)
                return &nodeHashes[mid];
            if(hash > nodeHashes[mid2].nodeHash)
                return &nodeHashes[mid];
            right = mid-1;
        }
        else
        {
            left = mid+1;
        }
    }
    return &nodeHashes[fallbackIndex];
}

static void msgQueueGroupHashesInit(int nodes, int hashesPerNode,
                                    MsgQueueGroupHashesT **ppQueueGroupHashes)
{
    int i;
    int err = 0;
    MsgQueueGroupHashesT *queueGroupHashes = NULL;
    int hashes = nodes * hashesPerNode;
    *ppQueueGroupHashes = NULL;
    if(!hashes) 
    {
        nodes = __MSG_QUEUE_GROUP_NODES;
        hashesPerNode = __MSG_QUEUE_GROUP_HASHES_PER_NODE;
        hashes = __MSG_QUEUE_GROUP_HASHES;
    }
    queueGroupHashes = msgQueueGroupHashes;
    if(hashes > __MSG_QUEUE_GROUP_HASHES)
    {
        queueGroupHashes = calloc(hashes, sizeof(*queueGroupHashes));
        assert(queueGroupHashes != NULL);
    }
    err = createMsgQueueGroupHashes(nodes, hashesPerNode, queueGroupHashes);
    assert(err == 0); 
    for(i = 0; i < hashes; ++i)
    {
        printf("Queue group index [%d], hash [%#x]\n", queueGroupHashes[i].nodeIndex,
               queueGroupHashes[i].nodeHash);
    }
    *ppQueueGroupHashes = queueGroupHashes;
}

static void testMsgQueueGroupHashes(int nodes, int hashesPerNode, 
                                    const char *key, const char *keyPrefix, int keys)
{
    int i;        
    MsgQueueGroupHashesT *queueGroupHash = NULL;
    MsgQueueGroupHashesT *queueGroupHashes = NULL;
    int hashes = nodes * hashesPerNode;
    int *nodeHits = calloc(nodes, sizeof(*nodeHits));
    msgQueueGroupHashesInit(nodes, hashesPerNode, &queueGroupHashes);
    if(!hashes)
    {
        hashes = __MSG_QUEUE_GROUP_HASHES;
    }
    for(i = 0; i < keys; ++i)
    {
        char *k = NULL;
        asprintf(&k, "%s%d", keyPrefix, i);
        queueGroupHash = msgQueueGroupGetNode((unsigned char*)k, strlen(k),
                                              queueGroupHashes, hashes);
        printf("Found node index [%d] for key [%s]\n", queueGroupHash->nodeIndex, k);
        nodeHits[queueGroupHash->nodeIndex]++;
        free(k);
    }
    if(keys)
    {
        for(i = 0; i < nodes; ++i)
        {
            printf("Hits for Node [%d] = [%d]\n", i, nodeHits[i]);
        }
    }
    if(key)
    {
        queueGroupHash = msgQueueGroupGetNode((unsigned char*)key, strlen(key), 
                                              queueGroupHashes, hashes);
        printf("Found node index [%d] for key [%s]\n", queueGroupHash->nodeIndex, key);
    }
    free(nodeHits);
    if(queueGroupHashes != msgQueueGroupHashes) 
        free(queueGroupHashes);
}

static char *prog;
static void usage(void)
{
    fprintf(stderr, "Usage: %s [ -n | nodes ] [ -i | hashesPerNode ] [ -k | key ] "
            "[ -p | keyprefix ] [ -c | keys] [ -h | help ]\n", prog);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    int nodes = __MSG_QUEUE_GROUP_NODES;
    int hashes = __MSG_QUEUE_GROUP_HASHES;
    int keys = 0;
    const char *key = NULL;
    const char *keyPrefix = "key";
    int c;
    opterr = 0;

    if( (prog = strrchr(argv[0], '/') ) )
        ++prog;
    else prog = argv[0];

    while( (c = getopt(argc, argv, "n:i:p:c:k:h") ) != EOF )
    {
        switch(c)
        {
        case 'n':
            nodes = atoi(optarg);
            break;
        case 'i':
            hashes = atoi(optarg);
            break;
        case 'k':
            key = optarg;
            break;
        case 'p':
            keyPrefix = optarg;
            break;
        case 'c':
            keys = atoi(optarg);
            break;
        case 'h':
        default:
            usage();
        }
    }

    if(optind != argc) usage();
    
    printf("Testing msg queue group hash with [%d] nodes, [%d] hashes per node, "
           "Test key [%s], [%d] keys and [%s] keyprefix\n",
           nodes, hashes, key ? key : "None", keys, keyPrefix);
    testMsgQueueGroupHashes(nodes, hashes, key, keyPrefix, keys);
    return 0;
}
