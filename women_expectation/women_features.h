/*A.R.Karthick:
  Fill the feature bits that are essential in this file
  and dont touch the main file.
*/
#ifndef _WOMEN_FEATURES_H
#define _WOMEN_FEATURES_H

/*This is a primary consideration for match*/
#define _IS_US      0x0

/*The below one isnt necessarily a primary condition for match:*/
#define _IS_FRIEND  0x1

/* One can be close before getting engaged,in which case ,he is a friend,
   or close _after_ getting engaged,in which case he is a volunteer for life.
*/

#define _IS_CLOSE   0x2

/*Is he qualified to a satiable extent*/

#define _IS_QUALIFICATION 0x3

#define _IS_SAME_CASTE   0x4

/*Is settled is a term that is specific to feature 1: _IS_US:
  Different people have different versions of settled:
*/

#define _IS_SETTLED      0x5

/*What!! I hear you say: 
  How can the total attributes be only 2,when there are many bitmasks
  above: Boy !! if you are not in US and not of the same caste,
  you dont have any chance- do you:
*/

#define TOTAL_ATTRIBUTES 0x2

#define _IS_US_MASK          ( 1 << _IS_US)
#define _IS_FRIEND_MASK      ( 1 << _IS_FRIEND)
#define _IS_CLOSE_MASK ( 1 << _IS_CLOSE)
#define _IS_SAME_CASTE_MASK   ( 1 << _IS_SAME_CASTE) 
#define _IS_QUALIFICATION_MASK ( 1 << _IS_QUALIFICATION )
#define _IS_SETTLED_MASK       (1  << _IS_SETTLED)

#define MARRIAGE_MASK ( _IS_US_MASK | _IS_FRIEND_MASK | _IS_CLOSE_MASK | _IS_QUALIFICATION_MASK | _IS_SAME_CASTE_MASK | _IS_SETTLED_MASK )

extern void load_person(char *name,const char *features_str,unsigned long permanent_features);
extern unsigned long lookup_features(const char *name);
extern char *trim_spaces(char *);

#define output(fmt,arg...) fprintf(stderr,fmt,##arg)

#define output_exit(fmt,arg...) do {\
fprintf(stderr,fmt,##arg);\
exit(127);\
}while(0)


#endif
