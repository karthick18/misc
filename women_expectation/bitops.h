/*Define the standard bitops.
Make this fast,hence use assembly.
Author: A.R.Karthick for MIR
*/
#ifndef _BITOPS_H
#define _BITOPS_H

#define ADDR(addr)  ( *(volatile long *)addr )

#define set_bit(nr,addr) do {\
__asm__ __volatile__("btsl %1,%0\n"\
                    :"=m"(ADDR(addr)):"Ir"(nr) : "memory" );\
}while(0)

#define clear_bit(nr,addr) do {\
__asm__ __volatile__("btrl %1,%0\n"\
                   :"=m"(ADDR(addr)) : "Ir"(nr) : "memory" );\
}while(0)

#define change_bit(nr,addr) do {\
__asm__ __volatile__("btcl %1,%0\n"\
                    :"=m"(ADDR(addr)) : "Ir"(nr) : "memory" );\
}while(0)

#define test_and_set_bit(nr,addr) ({\
int _old;\
__asm__ __volatile__("btsl %2,%1; sbbl %0,%0\n"\
                :"=r"(_old),"=m"(ADDR(addr) ) : "Ir"(nr) : "memory" );\
_old;\
})

#define test_and_clear_bit(nr,addr) ({\
int _old;\
__asm__ __volatile__("btrl %2,%1;sbbl %0,%0\n"\
                  :"=r"(_old),"=m"(ADDR(addr)) : "Ir"(nr) : "memory" );\
_old;\
})

#define test_and_change_bit(nr,addr) ({\
int _old;\
__asm__ __volatile__("btcl %2,%1;sbbl %0,%0\n"\
                  :"=r"(_old),"=m"(ADDR(addr)) : "Ir"(nr) : "memory" );\
_old;\
})

/*Define the first_first_zero and first_bit versions*/

static __inline__ int find_first_zero_bit(void *addr,int size) { 
  int res;
  __asm__ __volatile__(
                       "repe;scasl\n" 
                       "je 1f\n"
                       "subl $4,%2\n"
                       "xorl 0(%2),%4\n"
                       "bsfl %4,%0\n"
                       "subl %3,%2\n"
                       "shll $3,%2\n"
                       "addl %2,%0\n"
                       "1:"
		       :"=d"(res)
                       :"c"( ( (size) + 31 ) >> 5 ),"D"(addr),"b"(addr),"a"(-1),"0"(-1) );
  return res;
}

/*Find first bit that is set in a long of size bits:
 */
static __inline__ int find_first_bit(void *addr,int size) {
  int res;
  __asm__ __volatile__(
		       "repe; scasl\n"
                       "je 1f\n"
		       "subl $4,%2\n"
		       "bsfl 0(%2),%0\n"
                       "subl %3,%2\n"
                       "shll $3,%2\n"
                       "addl %2,%0\n"
                       "1:"
                       :"=d"(res)
                       :"c"( ( (size) + 31 ) >> 5 ),"D"(addr),"b"(addr),"a"(0),"0"(-1) );
  return res;
}

/*Find next zero bit and find_next_bit versions*/

static __inline__ int find_next_zero_bit(void *addr,int offset,int size) { 
  long *ptr = (long*)addr;
  int temp,res=-1,flag; 

  if(offset < 0 || offset >= size )
    goto out;
 
  ptr += ( offset >> 5);
  flag = (offset & 31 );
  
  if(flag) { 
    /*then we take the next byte into account and see if we can find a zero bit*/
    __asm__ __volatile__("bsfl %1,%0\n"
                         "jne 1f\n"
                         "movl $32,%0\n"
                         "1:"
			 :"=r"(temp) : "r"( ~(*ptr >> flag) )
			 );
    if(temp < 32 - flag) 
      return temp + offset;

    temp = 32 - flag; 
    offset += temp;
    ++ptr;
  }

  res = find_first_zero_bit((void*)ptr,size - 32*(ptr - (long*)addr) );
  if(res < 0 )
    goto out;
  res += offset;
 out:
  return res;
}

static __inline__ int find_next_bit(void *addr,int offset,int size) {
  long *ptr = (long*)addr;
  int flag,temp,res = -1;
  if(offset < 0 || offset >= size) 
    goto out;
  ptr += (offset >> 5);
  flag = offset & 31;
  if(flag) { 
    __asm__ __volatile__("bsfl %1,%0\n"
                         "jne 1f\n"
                         "movl $32,%0\n"
			 "1:"
			 :"=r"(temp) : "r"( *ptr >> flag ) );
    if(temp < 32 - flag)
      return temp + offset;
    temp = 32 - flag;
    offset += temp;
    ++ptr;
  }
  res = find_first_bit(ptr, size - 32 * (ptr - (long*)addr ) );
  if(res < 0 )
    goto out;
  res += offset;
 out:
  return res;
}

/*Find first zero bit*/

static __inline__ int __ffz(int value) { 
  int bit;
  __asm__ __volatile__("bsfl %1,%0\n"
                       "jne 1f\n"
		       "movl $-1,%0\n"
		       "1:"
                       :"=r"(bit) : "r"(~(value) ) );
  return bit;
}

/*Find first set bit*/
static __inline__ int __ffs(int value) {
  int bit;
  __asm__ __volatile__("bsfl %1,%0\n"
		       "jne 1f\n"
		       "movl $-1,%0\n"
		       "1:"
		       :"=r"(bit) : "r"( value ) );
  return bit;
}

static __inline__ int test_bit(int nr,void *addr) { 
  int old;
  __asm__ __volatile__("btl %2,%1; sbbl %0,%0\n"
		       :"=r"(old) : "m"(ADDR(addr)) , "Ir"(nr) );
  return old;
}


#endif

