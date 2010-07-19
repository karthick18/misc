/*Parse and load the womens expectation for each person listed in the file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "config.h"
#include "women_features.h"

static void get_and_load_person(char *name,char *buffer) { 
  register char *ptr ;
  unsigned long permanent_features =0;
  char features_str[0xff+1];
  strncpy(features_str,buffer,sizeof(features_str));
  do {
    if(! ( ptr = strchr(buffer,',') ) ) {
      ptr = trim_spaces(buffer);
      if(*ptr) {
	permanent_features |= lookup_features(ptr);
      }
      ptr = NULL;
    }
    else {
      char *str;
      *ptr++ = 0;
      str = trim_spaces(buffer);
      if( *str) {
	permanent_features |= lookup_features((const char*)str);
      }
      buffer = ptr;
    }
  }while (ptr);

  load_person(name,(const char *)features_str,permanent_features);

}

/*Config file parser for womens expectations:*/

int read_config(void) { 
  FILE *fptr;
  char buffer[0xff+1];
  
  if(! (fptr = fopen(CONFIG_FILE,"r") ) ) {
    output_exit("Unable to open womens config file %s:\n",CONFIG_FILE);
    goto out;
  }
  while(fgets(buffer,sizeof(buffer),fptr) ) { 
    int bytes = strlen(buffer);
    char *ptr = buffer,*name = buffer;
    if(buffer[bytes - 1] == '\n')
      buffer[bytes-1] = 0;

    while(isspace(*ptr) ) ++ptr;

    if(*ptr == COMMENT) continue; /*skip comments*/

    /*now check for the presence of name = features format*/
    if(!(ptr = strchr(buffer,'=') ) ) 
      continue;
    *ptr++ = 0;/*move ahead to the features*/
    name = trim_spaces(buffer);
    if( *name) 
      get_and_load_person(name,ptr); /*link this guy*/
  }
 out:
  return 0;
}
