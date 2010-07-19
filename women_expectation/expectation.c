/*    Copyright (C) 2004-2005 A.R.Karthick 
;    <a_r_karthic@rediffmail.com,karthick_r@infosys.com>
;
;    This program is free software; you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation; either version 2 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with this program; if not, write to the Free Software
;    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
;
; A.R.Karthick
; A code that resembles the general funda that is adopted by girls
; for marriages:
; Please go through the comments carefully.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bitops.h" 

/*Define the BITS representing the general
  required states | features:
*/
#include "women_features.h" 
#include "config.h"

/*Mark off the females opinions about us:
  have it above bit 20*/

#define  _IS_USELESS 20
#define  _IS_PARTIALLY_SELECTED 21
#define  _IS_OUTRIGHT_REJECTED  22
#define _IS_SELECTED            23

/*Now the structure that follows below is dependent on parental
  pressure:
  We give weightage based on parental pressure:
  The weightage is a percentage or
  the likely marriage hit rate of a guy in case of parental pressure:
  To make this simple,we compress the structure also to include
  names and bitmasks
*/

struct person_chances { 
  const char *name ;
  unsigned long useless_features;
  /*temporary features are the ones that can have temporary effect
   on a relationship and help pass ones time:
  */
  unsigned long temporary_features;
  unsigned long permanent_features;

  /*string equivalent of the feature masks*/
  char features_str[0xff+1];
  int opinion; /*whats the girls opinion*/
  /*link to next and previous chains for expectation pool 
    which may at first glance seem to vary:
  */
  struct person_chances *next;
  struct person_chances **pprev;
};

/*Now we initiate a structure where we elucidate the useless and the precious
  features of an ideal hit rate:-)
*/

struct person_chances ideal_person = { 
  name : NULL, /*I dont bother about names: Do I*/
  useless_features : _IS_FRIEND_MASK | _IS_CLOSE_MASK | _IS_QUALIFICATION_MASK | _IS_SETTLED_MASK,
  temporary_features : _IS_FRIEND_MASK | _IS_CLOSE_MASK ,
  /*as its evident: There is no link between this guy and the guy above:
   */
  permanent_features : _IS_US_MASK | _IS_SAME_CASTE_MASK,
  features_str : "us,same_caste",
  next : NULL,
  pprev : NULL,
};

/*The expectation pool for females especially for marriages:
  These would be loaded at run-time: That is as the life progresses :-)
 */
  
struct expectation_pool {
  /*maintain a list of the persons and their chances:
   These guys are optimum persons:
  */
  struct person_chances *head;
  struct person_chances **tail;
 
};

/*dynamic expectation pools*/
static struct expectation_pool *expectation_pool;

static inline void unlink_person(struct person_chances *ptr) { 
  if(ptr->next) 
    ptr->next->pprev = ptr->pprev;
  *ptr->pprev = ptr->next;
  ptr->next = NULL;
  ptr->pprev = NULL;
}

static inline void link_person(struct expectation_pool *ptr,struct person_chances *person) { 
  person->next = NULL;
  * ( person->pprev = ptr->tail ) = person;
  ptr->tail = &person->next;
}

static void destroy_expectation_pool(struct expectation_pool *ptr) {
  register struct person_chances *head;
  while( (head = ptr->head) ) { 
    unlink_person(head);
    free((void*)head);
  }
}

/*Link these guys into a chain*/

static inline void init_expectation_pool(struct expectation_pool *ptr) { 
  /*destroy previous expectation pools if any*/
  destroy_expectation_pool(ptr);
  ptr->tail = &ptr->head;
 
}
static inline struct expectation_pool *initialise_expectation_pool(void) {
  struct expectation_pool *ptr;
  if(! (ptr = malloc(sizeof(*ptr) ) ) ) {
    output_exit("Out of memory for expectation pool:\n");
    goto out;
  }
  memset(ptr,0x0,sizeof(*ptr));
  init_expectation_pool(ptr);
 out:
  return ptr;
}

/*Now we match features to bitmasks*/

struct features_map {
  const char *name;
  unsigned long features;
} features_map[] = { 
  { "us" , _IS_US_MASK},
  { "friend",_IS_FRIEND_MASK},
  { "close" ,_IS_CLOSE_MASK },
  { "qualified",_IS_QUALIFICATION_MASK},
  { "settled", _IS_SETTLED_MASK},
  { "same_caste",_IS_SAME_CASTE_MASK},
  { NULL, 0 },
};

unsigned long lookup_features(const char *name) { 
  struct features_map *head;
  for(head = features_map ; head->name ; ++head)  
    if(! strcasecmp(head->name,name) ) 
      return head->features;

  return 0UL; /*if it doesnt match,return 0*/
}

/*Config file parser*/

/*
 Trim leading and trailing spaces
*/

char *trim_spaces(char *str) { 
  register char *ptr = str;
  if(! str) 
    return ptr;
  ptr += strlen(str) - 1 ;
  /*trim trailing spaces*/
  while(ptr > str  && isspace (*ptr) ) *ptr-- = 0; 
  
  ptr = str;
  while(isspace(*ptr) ) *ptr++ = 0;
  return ptr;
}

/*Load the person into the expectation pool*/

void load_person(char *name,const char *features_str,unsigned long permanent_features) { 
  struct person_chances *ptr; 
  if(! (ptr = malloc(sizeof(*ptr) ) ) ) {
    output_exit("Out of Memory for person:\n");
    goto out; /*just to avoid gcc warnings*/
  }
  memset(ptr,0x0,sizeof(*ptr));
  if(! (ptr->name = strdup(name) ) ) {
    output_exit("Out of memory for person name(%s)\n",name);
  }
  strncpy(ptr->features_str,features_str,sizeof(ptr->features_str));
  ptr->permanent_features = permanent_features;
  /*now link this guy in the expectation pool*/
  link_person(expectation_pool,ptr);
 out: return;
}

/*The bits that are set,indicate missing links with the ideal expectation
    of women:
*/
static void get_missing_features(char *missing_str,unsigned long missing_features,int *count) { 
  int ideal_features[] = { _IS_US_MASK, _IS_SAME_CASTE_MASK };
  char *ideal_str[]    = {"not US based", "not of the same caste" };
  int i,bytes=0,total = sizeof(ideal_features)/sizeof(ideal_features[0]);
  for(i =0 ; i < total ; ++i) { 
    if( (missing_features & ideal_features[i] ) ) {
      /*found the missing feature: mark it*/
      (*count) ++ ; /*increment the missing count*/
      bytes += snprintf(missing_str + bytes,1024 - bytes,"%s%s",ideal_str[i], ( i < total - 1) ? "," : "" );
    }
  }
  missing_str[bytes] = 0;
}

/*Now analyse your potential with the ideal expectation pool
  of the women:
*/
static void process_each_person(struct person_chances *person) { 
  register const struct person_chances *ideal_ptr = &ideal_person;
  /*Now we analyse the persons features with respect to womens
    expectations:
  */
  if( (person->permanent_features & ideal_ptr->permanent_features) == ideal_ptr->permanent_features) {
    output("%s :I-as a Women feel \"Yeh Hi Hai Right Choice Baby\",coz you happen to be in US. OF A and be of the same caste\n",person->name);
    set_bit(_IS_SELECTED,&person->opinion);
  }

  else if( (person->permanent_features & ideal_ptr->permanent_features) ) {
    /*You are almost successful,but not yet through:
      Dump the missing link to yeh Hi right choice baby:
    */
    unsigned long missing_features =(person->permanent_features & ideal_ptr->permanent_features) ^ (ideal_ptr->permanent_features) ;
    char missing_str[1024 + 1];
    int count =0;
     /*this will toggle the bits that are not set and we can dump info.
      about the same:*/
    get_missing_features(missing_str,missing_features,&count);
    output("%s :I-as a Women suggest that you have %d missing features\n",person->name,count);
    /*dump the missing features*/
    output("%s :I-as a Women suggest that- You are %s\n",person->name,missing_str);
    output("%s :Hence-I as a Women suggest that you have %.2f percent chance of getting me.So hang around that I try and cycle back to you without any _real_ _perceivable_ guarantee\n",person->name,(TOTAL_ATTRIBUTES - count)*100.0/TOTAL_ATTRIBUTES);
    set_bit(_IS_PARTIALLY_SELECTED,&person->opinion);
  }
  else if( (person->permanent_features & ideal_ptr->useless_features) ) {
    output("%s : I-as a Women feel that you have temporary but pretty _useless_ features-\"%s\" to become my hubby\n",person->name,person->features_str);
    output("%s : I-as a Women suggest that you change your cast and try pissing off to US of A,to stand any chance of embracing me throughout your life\n",person->name);
    set_bit(_IS_USELESS,&person->opinion); /*mark my opinion*/
  }
  else {
    output("%s :I-as a Women suggest that you are a Nincompoop trying to marry me with \"%s\" features that have no credibility in my expectation pool\n",person->name,person->features_str);
    set_bit(_IS_OUTRIGHT_REJECTED,&person->opinion);
   }       
}

struct programmers_ideal_persons { 
  const char *name ;
  const char *features;
}ideal_persons [] = { 
  {"Sundar","A living GEM with top notch qualities like IIT GRAD,struggled for recognition and food, earned his position, has an unmatched helping tendency\n"},
  {"Madhan","A living GEM with top notch qualities like hard working,intelligence personified,earned his reputation and position after craving for food and shelter\n"},
  {NULL, NULL},
};

/*This is what the programmer feels about missed persons
  which fall into his category as GEMS, 
  and considers it as a LOSS of the OPPOSITE SEX:
*/

/*Lookup the programmers ideal list of persons*/

static struct programmers_ideal_persons *
lookup_ideal_person(const char *name) { 
  register struct programmers_ideal_persons *ptr;
  for(ptr = ideal_persons ; ptr->name ; ++ptr) 
    if(!strcasecmp(ptr->name,name) ) 
      return ptr;
  return NULL;
}

/*This routine expresses the programmers feelings 
  related to the girls opinion:
 */

static void what_programmer_feels(void) { 
  register  struct person_chances *person ;
  output("\n\nProgrammer Speaks for the Person (Can he) ?\n\n");
  for(person = expectation_pool->head ; person ; person = person->next) { 
    /*see if he satisfies the programmers list of ideal persons*/
    struct programmers_ideal_persons *ptr = lookup_ideal_person(person->name);
    if(ptr && !test_bit( _IS_SELECTED, &person->opinion) ) { 
      output("What can I say about your opinion on \"%s\".",ptr->name);
      output("I can only say-He is a %s\n",ptr->features);
    }
    else if(test_bit(_IS_USELESS,&person->opinion) ) { 
      /*I request the women to give this guy a second chance:
       */
      output("Hey Women- I can only say that the person \"%s\" deserves a second chance\n",person->name);
      output("If you are rejecting him for Parental Pressure,than I am sorry to say that you are a coward,for he has genuine Indian Qualities without being in US OF A\n");
      output("Please give him a second chance Mam.Please...\n");
    }
    else if(test_bit(_IS_PARTIALLY_SELECTED,&person->opinion) ) {
      output("Hey \"%s\" !! Please be patient till the women tries to take a cyclic stroll down the Mens lane.\n",person->name);
      output("You are lucky that you are still in her list\n");
    }
 
  }
}
         
/*Now we get on with the act of processing persons from the expectation pool
 */
static void process_persons(void) { 
  register struct person_chances *ptr;
  for(ptr = expectation_pool->head ; ptr ; ptr = ptr->next) { 
    /*process each person in the expectation pool*/
    process_each_person(ptr);
  }
  what_programmer_feels();
}

int main(int argc,char **argv) { 
  if(! (expectation_pool = initialise_expectation_pool() ) ) 
    goto out;
  read_config();
  process_persons();
  destroy_expectation_pool(expectation_pool);
 out:
  return 0;
}
