/********Hi Parents+Relatives,
         A.R.KARTHICK is in a fix.He just now had a conversation with his Girl
         Friends Mother,and was asked to get engaged and Married within 2 years.I
         told her,that I need atleast 3 years,to get settled..And Moreover I want to
         gain knowledge..Knowledge is all that I crave for and I am still way behind
         in that department.
         He needs some Help.He is serious.There is absolutely no element of joke in
         this Mail.And every Word in this Mail is important.
         I request each and every individual to which This mail has been delivered to
         be silent about the contents of the Mail.Its a request.Please dont reveal
         the Contents of this Mail to anyone else.
         Dear Mom,Pa and Sai.Please,dont reveal the contents of this Mail to my
         friends,to whom I have not revealed,without My Consent.I trust each and
         every individual.And if you manage to Break my trust,then I will be
         extremely Upset and will not talk to them.Be it PA,OR MA OR BROTHER,OR ANY
         CHITTIS AND ATHAIS or MAMAS.For once,I am dead serious.
         Please take a 'HARD COPY' of this MAIL and analyse it at your own
         convenience.I expect My Parents and Relatives to Like my Girl Friend,as she
         is extremely Simple.I expect them to believe in my Choice.
         I am not going to reveal the Name of my girl friend just like that.
         Infact You have to reveal her name,through this mail of mine,which presents
         all the Attributes of My Girl Friend in a 'C' Code.
         I will never reveal her Name even if you ask me after reading this Mail.You
         have to find her details through this mail,revealed by A.R.KARTHICK in a
         'FORM OF A C PROGRAM' but every Bit of the Program is explained,which doesnt
         entail the Knowledge of 'C' and every declaration is in Tune with my Girl
         Friends Attributes.

         The PROGRAM OF HIS LIFE.
         THE Mail of HIS FUTURE..
         BY A.R.KARTHICK.
         Released on the 9th of OCTOBER,2000
         TIME-1:50.53SECS EST.
**************************/
/*************A Very Important Mail..which will decide A.R.KARTHICKs
Future..

First I have been getting reports about the unbearable length and Belaboring
contents of my Emails..But this Mail is 'Very Special'..and entails each and
every individual to which this mail has been directed,to patiently analyse
this Mail.If possible,I would advise my Relatives and Parents to take a
'HARD COPY' of this mail so that they can analyse the contents of this mail
at their convenience..and arrive at a conclusion..

Dear Parents & Relatives,

This is a very important Mail which can have direct bearance on the future
of A.R.KARTHICK.This Mail reveals the Innermost details of A.R.KARTHICKs
Girl Friend,about whom he has been silent..
I thereby request each and every individual to read the mail,irrespective of
whether he possesses adequate 'technical know-how' to browse through this
mail.This mail explains each and every technical detail..and will not pose
any readability problems.I have tried to be 'as clear as possible'.
You will find that an Amazing Effort has been Put to Make this Mail a
Success..You will feel it while you read the Mail.

I have  explained everything that is required to analyse this Mail..
The naming Conventions that A.R.KARTHICK has employed also goes inline with
the thinking domain of his relatives,or by that matter any common man..
which will make the mail readable for any person, irrespective of caste and
creed,irrespective of whether he possesses the technical knowledge or not..
So,Please go through this mail..and Dont for 'Heavens Sake' delete the mail
'OFF THE SERVER'.I request you to go through this mail..Its an earnest
request,made from the Heart..I really mean it..Please go through this
mail..at your convenience..Its a 'Must Read'.
******************************/
/***Oct. 2000 **/
/**CopyRight of this Mail held by A.R.KARTHICK and his Girl Friend...
   Reason : For the Magic Integer Equivalent of his girlfriends Name..which
   A.R.KARTHICK Used, to BitEncode his Girl Friends Name to present it to his
   Relatives and Parents..He has presented this,as he was asked to present by
   His Girl Friend..And she is A.R.KARTHICK'S  'Present Career Driver'.

   ******'The Mysterious Aspect of A.R.KARTHICK Unleashed..'
   ******'Inscrutable Are the Ways Of A.R.KARTHICK'

   ************By A.R.KARTHICK************************

   ************In his own Inimitable Style**********

   ***********************/

/******A 'C' program which embeds all the attributes of my girl friend and
       presents to the 'READER',the magical Number of my Girl Friend..*****/

/****I have revealed the Magical Number associated with my Girl friend at
     the fag end of the mail and has explained the Salient Features of the
     Number..*****/ /******But To Increase The Readers Curiosity,I hereby present
                           the Magical number of my girl Friend..
                           Magical 12 Digit,40 Bit Number of A.R.KARTHICKs Girl friend Unleashed..
                           Number equals..
                           3 5 3 2 8 2 3 1 2 2 5 7
                           ***Please Read the Mail for Complete Details..**/

/*
  Again,Dont be afraid with the 'C' program..Its only an interface chosen by
  A.R.KARTHICK to elaborate about his Girl Friend..The Comments embedded in
  the Program Explains Everything,But seeks for some Discovery on the Part of
  the Reader..But it provides all the Tools to the User to crack his Girl
  Friends Name..
*/

/* Some Tips for Browsing through the mail.
   If you find the Initial Stage,a Bit unreadable,Then safely Skip through
   it.But please Read the Comments,As they explain all the actions in the
   Code..
*/

#include<stdio.h>
#include <stdlib.h>
/* the number of effective bits in my girl friend,is 40..that is each
   character,although is 8 bits wide,takes only 7 bits for the alphabets.That
   is to say that the ascii value of character 'a' is 97 and that takes only 7
   bits as the eight bit is OFF.and its value isnt significant.That is 97 lies
   between 2**6 and 2**7,that is between 64 and 128,and any guy can see that it

   lies in the 7 bit zone */

#define MAX 100
#define NBITS 8 //each character in my girl friends name,holds 7 bits.

/*now define the shift operations for each character of my girl friend */
/* this will give you the hint regarding the number of characters in my girl

   friend,and already you know that the maximum characters can only be 8,if you

   consider the size of long long,which is 64 bits..but doesnt the structure
   definition in the form of a bit field,give you the hint.the max is 8
   characters,and the real length of my girl friends name is ...? for you to
   guess..go through the code..You will guess it in a 'jiffy' if you go through

   the code.*/

#define CONSTANT (NBITS*5)

/*each shift operation denotes the shift operation for each character of my
  girl friend.This should unleash the number of characters in my girl friend
*/


#define SHIFT1  (CONSTANT - NBITS)
#define SHIFT1_MASK ( (1L << SHIFT1)-1)
#define SHIFT2  (SHIFT1-NBITS)
#define SHIFT2_MASK ( (1L<<SHIFT2) - 1)
#define SHIFT3  (SHIFT2-NBITS)
#define SHIFT3_MASK ( (1L<<SHIFT3)-1)
#define SHIFT4  (SHIFT3-NBITS)
#define SHIFT4_MASK ((1L<<SHIFT4)-1)
#define SHIFT5  (SHIFT4-NBITS) //dummy..no shift at all..its zero as its the last character of my girl friend
#define SHIFT5_MASK ( (1L<<SHIFT5)-1)
/*shift operations complete..Now you would have got hold of the number  of
  characters in my beloved..*/

/* a generalised macro for getting the BIT configuration of all the
   chracters in my girl friend.When the bits are embedded,it will give you the
   complete bit set,which is one full 40 bit set..representing the characters
   in my girl friend..*/

#define GENERAL(A,B,C,D,E,F)                                        \
    F= ( \
        ( (A)<<SHIFT1 ) |                   \
        ( (B)<<SHIFT2 ) |                   \
        ( (C)<<SHIFT3 ) |                   \
        ( (D)<<SHIFT4 ) |                   \
        ( (E)<<SHIFT5)                      \
         )

/* the above macro embeds the 40 bits successfully..obviously the return
   value of my girl friends 'names integer equivalent' has to be stored in a
   "long long" (64 Bit,but I have taken only 40 out of the 64 bits) field of my

   Bit Field structure */

/*in order to enable you guys to crack each character set,I am presenting
  herewith the BIT MASKS for tracing the characters of my girl friend.This BIT

  MASK can be used by you guys in your user space program to get each
  character of my girl friend..and thus catching me red handed by revealing my

  girl friends name. So here we go..I will also reveal the 40 bit set on which

  you can use these Bit masks to trace my girl friends name.Infact I have
  already enclosed a Function which reveals my girl friends Name,Location and
  Mother Tongue.*/

#define BITMASK 0xFF //hey guys..YEDI PAKDE TOH MAAF KARNA.I LOVE HER LIKE CRAZY..

/*the second trivial Bit Mask is for encapsulating my girl friends name into

  a  '40 Bit Entity' as the structure that i am going to define for the length

  of my girl friends name will hold only 40 bits..and not 64 bits.Doesnt make
  much of a difference isnt it..But improves portability and incorporates
  implementation specific features for other Love Birds. The below macro only
  represents the 40 BIT ON number in HEXADECIMAL.In Long Long Integer
  representation,it will be 2**40 - 1,which is 2 to the Power of 40 minus 1,in

  words. In simple terms,you should know that the integer 3 has a binary or
  bit value of 011 which is 2 BIT ON,which is nothing but 2 power 2 minus 1
  ,in words.So a 40 BIT ON number will have the value 2 power 40 minus
  1.Remember,
  I say "Long Long Integer Representation",as an Integer in a 32 Bit Machine
  Architecture can hold only 32 bits.and so the Max value,is 2**32 - 1 or 2 to

  the Power of 32 minus 1 in words. In Sparc Systems,I need not use any long
  long declarations as its a 64 Bit Architecture..But I am unaware of any
  other features in Sparc.. */

#define NAMEBITMASK 0xFFFFFFFFFF
//the above macro represents 40 BIT ON..like the number having the BIT CONFIGURATION AS 1 1 1 1..and so on till 40 counts..

/*now to trace each character of my girl friend,i am presenting you the bit
  masks.use them in your user space programs to trap me..common squeeze me*/

/*The characters of my girl friends name as extracted from the 40 bit
  set,represented by argument A. in these MACROS */

#define TRCHR1(A) (((A)>>SHIFT1) & BITMASK)
#define TRCHR2(A) (((A)>>SHIFT2) & BITMASK)
#define TRCHR3(A) (((A)>>SHIFT3) & BITMASK)
#define TRCHR4(A) (((A)>>SHIFT4) & BITMASK)
#define TRCHR5(A) (((A)>>SHIFT5) & BITMASK)

/* all characters will be successfully traced by the user,if he replaces the

   replacement argument A,in the above macros by the 'magical number' value
   that i have already enclosed in this code..*/

/* all the Bit operations Macros defined for my girl friend,enable me to
   evaluate the 40 bit equivalent of my girl friends name. */

/*Now the length Bit Field structure for my girl friend */

/* I have optimised the length part of my girl friend to accomodate for 64
   bits or 8 bytes or 8 characters instead of 32 bits or 4 bytes or 4 chars */

/*This was done by me,to enable Love Birds to use this program to Bit
  Encode their Girl friends Name consisting of Max 8 characters,while
  revealing to their Parents,Friends and Relatives.But Remember Love Birds, to

  tweak the code to encode a girl friends name of more than 8 characters or 8
  bytes or 64 bits.*/

//a typedef definition only to improve readability of the code

typedef long long MyGirlFriendsNameInsideBits;

struct MyGirlFriendsLength{

    MyGirlFriendsNameInsideBits l : 40; //i have used long long to enable me to hold 64 bits as Max grip..

    /*But I effectively hold only 40 bits..as only 40 bits are required for my
      girl friend..Here again,Love Birds,you have to tweak the code,and set it to
      the correct length..I presume,a modification of the program with the length
      of the girl friends name,being passed as a command line argument.That makes
      the code a Bit Robust..I leave it to you to decide..After all,this code is
      Implementation and Person Specific. */

};
/* the above was a stupid structure meant only for improving the readability

   of the code */
/*
  I will define the Main structure representing the Attributes and
  Specifications of my Girl friend later in this code. Thats the Structure
  that you will find 'The Most Interesting'..
*/
/*
  Now in order to hide my girl friends name from you guys,I define the
  function used to get her name as an extern.This maintains the continuity of
  the Code and at the same time,improves readability..and reduces dependence
  on input routines in this section of the code,which is entirely dedicated to

  Encode My girl friends Name as a 40 BIT SET. and present her Attributes in
  the form of  BIT MASKS.
*/

/*
 * This is meant to be the hidden function that should come from an external source and not visible
 * in the code :-)
 */

//extern char *MyGirlFriendsName(); //this function returns my girl friends name.I have purposely hidden it from your eyes,But i will always present tools to trace my Girl Friends name..

#define MyGirlFriendsName() ({"RADHA";})


/*A function prototype for Encoding My Girl Friends Name,Takes my GirlF
  Friends Name as an Argument.*/

MyGirlFriendsNameInsideBits BitEncodeMyGirlFriendsName(char
                                                       *mygirlfriendsname);

/*The Prototype declaration of the Most Important Function from the Readers
  Point of View,which exposes the Name,Location and Mother Tongue of my Girl
  Friend. */
void Check_Everything_About_My_GirlFriend
(MyGirlFriendsNameInsideBits magicnumber);

char *BitConvert(MyGirlFriendsNameInsideBits);

/* The start of Main */

int main(){
    char *gfname; //trap my girl friends name in this variable

    char *BitConvertYourMagicNumber;//this is for you guys exclusively..

    /*create an instance of the "length of my girl friends name structure" for
      storing the 40 bit set encapsulating my girl friends name */

    struct MyGirlFriendsLength gflength;

    gfname=MyGirlFriendsName();
    /* the above function MyGirlFriendsName,returns my Girl friends Name.But as
       its an Extern routine,Its not visible to your eyes. */

    /*Now comes the most important function which Bit Encodes my girl friends
      name.The function returns the 64 bit number  of my girl friends Name,which i

      will have to convert into a 40 bit by 'AND'ing with a 40 BIT 'ON' MASK that
      I defined as a MACRO in 'NAMEBITMASK' */

    gflength.l=BitEncodeMyGirlFriendsName(gfname) & NAMEBITMASK ;

    /*now i print the magic number..*/

    printf("Karthicks Girl Friends Magic number=%#llx\n", (long long)gflength.l);

    /*
      Now, I am caught in this Magic 40 BIT number,which if you use with my
      TRCHR[1-5] macros,I am dead..I am caught..Nopes..Please forgive me.Check out

      her attributes in the structure that I am going to define later.in this
      code..*/
    /*
      For improving the Chances of your Trace routines,I am also embedding
      herewith a BIT Conversion function for converting the 40 Bit NUMBER
      representing my girl Friend,into a binary,for your kind Perusal.This will
      further improve your chances for hacking or shall I call it 'Cracking'( i
      reckon the usage of the latter to the former,as its the best fit. in this
      context ) my
      Girl Friends Name */

    BitConvertYourMagicNumber=BitConvert(gflength.l);

    /* This displays the complete 7 Bit Packs.of my Girl friends Name */

    printf("Karthicks Girl Friends BitConvertedNumber:\n[\n%s\n]\n",BitConvertYourMagicNumber);


    /*most important function which if used will completely reveal the name of
      A.R.KARTHICK's girl friend..I should not have presented this Function.It
      calls For Danger..*/

    Check_Everything_About_My_GirlFriend(gflength.l);//this function will say it 'All'.

    exit(0);  //exit from code..
}

/*definition of the most important routine to improve your tracing chances.
  Check out the usage of the "__extension__ key word for defining the function

  which will return a "long long",a LA "64" bit Magic Number.*/

__extension__
MyGirlFriendsNameInsideBits BitEncodeMyGirlFriendsName
(char *str)

{

    MyGirlFriendsNameInsideBits holdmagicnumber ;

    /*Since this program is largely dedicated to my girl friend,i literally
      assume things here..(thats dirty isnt it.) and call the Pre defined Macro to

      extract the 40 Bit set.*/

    /****Here comes the Call to the Macro****/

    GENERAL((MyGirlFriendsNameInsideBits)*str,(MyGirlFriendsNameInsideBits)*(str
                                                                             +1),(MyGirlFriendsNameInsideBits)*(str+2),(MyGirlFriendsNameInsideBits)*(str
                                                                                                                                                      +3),(MyGirlFriendsNameInsideBits)*(str+4),holdmagicnumber);

    //now holdmagicnumber.APUN KA PARDA FAAS KAR DEGA..
    return holdmagicnumber;//this is the magic number..of my girl friends name

}
/* this  cracks the number and displays my girl friends name.. */

/*ARE YAARON..YEDI PAKDE TOH A.R.KARTHICK KOH AAP JOH SAZA DOGE, USSE WOH
  MANZOOR HAI.. */

void Check_Everything_About_My_GirlFriend
(MyGirlFriendsNameInsideBits magicnumber){

    char str[6];//six character to hold in the string.

    int i=0;

    str[i]=TRCHR1(magicnumber);//trace first character of my girl friend
    i++;
    str[i]=TRCHR2(magicnumber);//trace second character of my girl friend
    i++;
    str[i]=TRCHR3(magicnumber);//trace third character of my girl friend
    i++;
    str[i]=TRCHR4(magicnumber);//trace fourth character of my girl friend
    i++;
    str[i]=TRCHR5(magicnumber);//trace fifth character of my girl friend
    str[++i]='\0';//last character should be always '\0' in 'C'.

    /*******
            Girl Friends Name Cracked from the Number and Displayed..I should not have
            Revealed It..I am Digging my Own Grave..But It had to Happen Some day.
    **/

    printf("Karthicks girl friends Name is '%s'\n",str);

    /***Next I define the Location flags,just to keep you guessing.It will be
        easy to track the location of my girl friend if you understand the Bit masks

        I define for the location.The names will explain everything..Infact they
        will explain it all .Or shall I do the check and Display it for your
        perusal.Okay Done..I will display her present Location.*/

    /*The location flags come in alphabetical order*/

    /*I will reveal the hint to find the location in a psuedo segment of the
      code,using the  location mask to crack the present location of my girl
      friend*/

#define BANGALORE       (1<<0xF) //16th Bit On
#define MUMBAI          (1<<0xE) //15th Bit On
#define CALCUTTA        (1<<0xD) //14th Bit On
#define DELHI           (1<<0xC) //13th Bit On
#define OSLO            (1<<0xB) //12th Bit On
#define STOCKHOLM       (1<<0xA) //11th Bit On
#define CHENNAI          (1<<0x9) //10th Bit On

    /* this is the location mask which will enable you to track the exact
       location of my girl friend.I will use the LOCATIONMASK and display her
       current location. */

#define LOCATIONMASK    (0x3FF) //10 Bit ONS..i have revealed it..Havent I..
    /*you have to perform a Bit Wise And.That is 'And' this location mask with
      any of the named locations,say 'BANGALORE'.*/

    if ( (LOCATIONMASK & BANGALORE)==BANGALORE){
        /* then the present location of my girl friend is BANGALORE. */
        printf("Karthick's Girl Friend '%s' is currently in %s\n",str,"BANGALORE");
    }
    //do the same check with all the other locations.
    else if( (LOCATIONMASK & MUMBAI)==MUMBAI){
        /* then the present location of my girl friend is BOMBAY. */
        printf("Karthick's Girl Friend '%s' is currently in %s\n",str,"MUMBAI");
    }

    else if((LOCATIONMASK & CHENNAI)==CHENNAI){
        /*present location is Madras*/
        printf("Karthick's Girl Friend '%s' is currently in %s\n",str,"CHENNAI");
    }

    //I simply Omit the rest.So it should be heartening to Note that my girl friend hails from India..

    /* now i reveal the Mother Tongue of My girl friend..I dont believe in Caste

       system and hence,I simply ignore that attribute..I am sorry..But thats My
       attitude towards life..First Preference for 'Homo Sapiens'..They are at the
       top..No caste politics please..
    */
    /* again i give each bit to the languages..and then define a BIT MASK.
       for you to extract her language or shall I extract her Language for you.
       Okay Done.A.R.KARTHICK will extract his Girl Friends Language for you. The
       language definitions are in Alphabetical order.*/

#define ANDHRA     040 //sixth bit for 'GOLTY',TELUGU..
#define HINDI      0100 //bit 7 for HINDI,encloses UP+RAJASTHAN+BIHAR.
#define MARATHI     0200 // bit 8 for AMCHI MUMBAI
#define NORWEGIAN  0400 //bit 9 Hmm..Interesting isnt it..this should raise some eyebrows..But check out the Bit Mask before you jump to premeditated conclusions.. bit 9 for norwegian
#define SWEDISH    01000 // bit 10 for a swedish
#define TAMIL      02000 //bit 11 for TAMIL


    //now the Bit mask to extract the language..of my girl friend.

#define LANGUAGEMASK (0x3F) //i wont say anything..you crack..or I crack it for you..Okay Done..I will crack it for you..

    //'AND' this with the above language..and get my girl friends mother tongue..do this..
    if ((LANGUAGEMASK & ANDHRA) == ANDHRA) {
        /*then girl friends language is telugu*/
        printf("Karthicks Girl Friend '%s's Mother Tongue is %s\n",str,"TELUGU");
    }
    else if((LANGUAGEMASK & TAMIL) == TAMIL){
        /* then girl friends language is tamil*/
        printf("Karthicks Girl Friend '%s's Mother Tongue is %s\n",str,"TAMIL");
    }
    else if((LANGUAGEMASK & HINDI)==HINDI){
        printf("Karthicks Girl Friend '%s's Mother Tongue is %s\n",str,"HINDI");
    }
    else if((LANGUAGEMASK & MARATHI)==MARATHI){
        printf("Karthicks Girl Friend '%s's Mother Tongue is %s\n",str,"MARATHI");
    }
    /*I stop the check.So you know that her native language is either TELUGU,or
      TAMIL or HINDI or MARATHI*/

} //I stop with these Displays..about my Girl Friend..


/**************The Qualities of my girl friend Unleashed***********

Each Bit signifies a 'particular defined' quality in my girl friend.I will
define a Mask that will reflect her strength in each of the qualities.
That is to say,that if i represent her Voice with the Bit configuration as
(10),you can see that the second bit,that is if you go from right to left,is

ON,as it contains '1'.Now if the second Bit in my Quality mask also contains

a '1',then you assume that my girl friend has an excellent voice.If the
second bit in the quality mask contains a '0',then you assume that she lacks

in that department.I would like your views on expanding this quality
declarations.I dont consider Beauty as a quality,as I reckon that its the
integration of all the below qualities.
*/

#define TOTAL_QUALITIES_KARTHICK_HAS_DEFINED 0x8 //i specify only 8 qualities

enum MyGirlFriendsQualities{

                VOICE=01, //this is an octal representation.the first bit from the right is for voice.Please check the quality mask to see if it tallies.

                    RESPECT=02,//this represents the second bit from the right.that is in the binary representation of 2,which is (10),1 is in the second position from the right.

                    ADAPTABILITY=04,//this represents the third bit from right to left.

                    DIGNITY=010,//this represents the fourth bit..same alignment..as the previous ones,integer equivalent=8,binary equivalen=1 0 0 0.

                    FLEXIBILITY=020, //this represents the fifth bit.integer=16

                    SIMPLICITY=040, //this represents the sixth bit.integer=32

                    ARROGANCE=0100, //represents the seventh bit.integer=64

                    INTELLIGENCE=0200,//represents the eight bit.integer=128

            }; /*end of the quality structure*/


/* here comes the Bit mask for Quality.
   Hack this mask into Bits,and check whether they are On or Off.
   To check for the results.If the Bits are On,then assume,she is excellent in
   that department,if the Bits are Off,then assume she lacks in that
   department.
   That is to say,that if i define the Quality mask as,
   say - 0x26 ,which in integer representation is the number 38,which has a
   binary equivalent of (0 0 1 0 0 1 1 0) ,(i take 8 bits as i represent 8
   qualities in my girl friend),
   This quality mask signifies (i take from right to left as i have defined the

   quality bits), that my girl friend doesnt have a good VOICE (as the first
   bit from the right is 0 or OFF),
   has RESPECT(as the second bit is 1 or On),
   is ADAPTABLE (as the third bit is 1 or ON),
   is not dignified(as the fourth bit is 0 or OFF),
   is not flexible (as the fifth bit is 0 or OFF),
   is SIMPLE in looks and nature (as the sixth bit is 1 or ON),and is not
   ARROGANT(as the seventh bit is 0 or OFF) and is not INTELLIGENT(as the eight

   bit is 0 or OFF). This was only an example.Dont take it to be the traits of
   my GIRL FRIEND.s.Offcourse,she is Intelligent..My Bit Mask will Show that.*/

/*Here i define the real quality mask that will reflect my GIRL FRIENDS
  QUALITIES..as suggested in The Bit Mask Pattern ***/

#define QUALITYMASK (0xBF) //integer equivalent=191.
/**7 BIT ONS..1 BIT OFF..you have got it now,havent you..Implies,that
   the Positions in which the Bits are ON or have '1',shows she is excellent,in

   those departments. and the position(taken from right to left) in which the
   Bit is Off or '0',shows that she lacks in that department.Ok done.
   Shall I show you the Quality Mask in Bits.
   Okay Done..Here comes the Quality Mask of the integer equivalent 191
   in Bits..
   ( 1 0 1 1 1 1 1 1).You can see that she lacks in 'Arrogance',as the seventh
   Bit from the right,is '0',or OFF.and she possesses the rest in abundance..
******/

/********The Bio Data of My Girl Friend Unleashed***************

         here comes the entire biodata of my girl friend.in the form of a 'C'
         tstructure.But before I define the structure,I do some declarations..some
         enumerations..on her parental status and stuffs like that.. Some operation
         definitions..etc..
         First..Parental status..

         I have taken 2 bits for her parents.and a parental mask which will signify
         whether both the father and the mother are alive,or whether one of them is
         alive and the other person is 'no more'.The same logic can be applied to
         check for the status of the parents.
*********************************************/

enum MyGirlFriendsParents{

    MOTHER=01, //the first bit is for the mother.number 01 is in octal,base 8 as any number starting with digit '0' is interpreted as an octal by the compiler..but in any case,01 is equivalent to number 1,but 010 is equivalent to number 8 in octal.

        FATHER=02, //the second bit is for the father.Integer=2

};

#define PARENTALMASK 0x1

// the above is the mask to extract my girl friends parental status.that is ,
//if((PARENTALMASK & FATHER) != /*not equal to */  FATHER)
/*then my girl friends father is 'no more'..in this materialistic world..
 */

/********Operations to be defined By our Parents on 'Us'*******


***********Now I define The Most Important Structure****************

'Parent Implementation Specific' operation structure for A.R.KARTHICK and
his girl Friend.
This structure is directly dependent on our parents.I assume that these
operations will be performed by my parents with the consent of my girl
friends parents in near future.
I use the classical 'C' approach which can be used as a substitute for
object oriented programming in 'C' using pointers to Functions as the
members.But for persons who dont know 'C',dont get afraid,The function names

will explain all the operations that need to be performed.
**************************/

struct Operations_To_Be_Performed_By_Parents_On_Me_And_My_GirlFriend

{

    int (*MyGirlFriendLikeDislike)(char *MyGirlFriend);

    /*************explanation of the above declaration*****
the above function takes my girl friends name as the argument and performs a

'like or a dislike operation on her'..by my parents.the function returns
either 1 or 0,signifying 'like' and 'dislike' respectively.If the function
returns '1',then my parents have liked my girl friend.They will surely like
her..as she is really very good and is extremely simple by nature..But again

the operation is to be defined by my parents..this field to be filled in by
my parents..
    ********************************************/

    int (*KarthickLikeDislike)(char *Karthick);
    //the above operation has to be performed by my girl friends parents. on me.similar as the previous operation.

    /***********if the above operations ends up in a success,that is if both of
them define the 2 operations as 'SUCCESS'..then the final 2 operations are
to be performed.
    **/

#ifdef SUCCESS //this has to be defined by our parents..

    void (*Engagement)(char *MyGirlFriend,char *Karthick);
    /**
       the above operation performs an engagement between me and my girl friend.The

       function doesnt return..And i expect it to be a success..
    *******/

    //and finally ..the last..operation..The Marriage..

    void (*Marriage)(char *MyGirlFriend,char *Karthick);

    /*******marriage between Karthick and his Girl friend..****/


#endif

}; //end of operations structure.

typedef struct
Operations_To_Be_Performed_By_Parents_On_Me_And_My_Girl_Friend OPERATIONS;
//typedef it for namesake..its such a long name..i reduce it to OPERATIONS..

//now I define the main structure which is dependent on the operations structure to take shape..

/*this is the main structure for my girl friend..which embeds all the
  attributes in her..its quite a big structure if you expand it..And is
  Virtually
  an  'Asymptotic Curve'..It doesnt have an End..
  But I had to terminate it..Somehow..
*/

/*******The Main Structure embedding everything that my girlfriend possesses

 ******/

struct MyGirlFriendsBiodata{

    char *gfname; //my girl friends name
    /***
        name has to be filled in by you after you decode the Bit Encoded set,or the
        Magic Number which i am going to reveal again,
        just after this structure to enable you to crack my girl friends name,using
        the techniques or the tools that i have provided,or using your own method..i

        think i have covered all the methods for tracing my girl friend,if given the

        magical number.I have also provided the function that displays her
        Name,Location and Mother Tongue.
    *************/

    struct MyGirlFriendsDoB *dateofbirth;

    //points to the date of birth structure which i will present..to help you decode the date of birth of my girl friend.

    enum MyGirlFriendsParents parentalstatus;//to enable you to check the parental status of my girl friend..

    struct MyGirlFriendsFamily *heritage;//pointer to the family heritage of my girl friend or for That Matter any Individual..

    /* the below 2 structures were the brain child of my beloved friend in OSLO
       and my room mate, MR.UMA MAHESHWARAN,Himself a Cold Fusion Wiz and now on to

       designing Image Filters.Thanks Umesh.I shall always be indebted to you
       through out my life For your valuable suggestions in enlightening this
       structure..*/

    /* first one suggested by Uma Maheshwaran..To add a Hobbie list..of my
       GirlFriend. */

    struct MyGirlFriendsHobbies *hobbies;

    /*Second one suggested by UmaMaheshwaran to add likes and dislikes list to
      my Girl Friends Biodata structure */

    struct MyGirlFriendsLikesAndDislikes *likesanddislikes;


    struct MyGirlFriendsQualification *ptr;//this is a pointer to the structure which will define my girl friends qualifications..

    enum MyGirlFriendsQualities girlfriendsqualities; //to extract the qualities of my girl friend..or to check the qualities of my girl friend..


    //and finally,the operation structure which is dependent on our parents reactions..

    OPERATIONS *operations; //points to the operations to be performed on me and my girl friend.Its a 'Parent Dependent' structure

}; //end of the structure..

/******Qualification structure for my girl friend Unleashed*****/

struct MyGirlFriendsQualification{

    struct DEGREE *degree;//pointer to The DEGREE structure

    struct PROGRESS *progress;//pointer to the current progress of my girl friend..
};

/*the degree structure for my girl friend Unleashed */

struct DEGREE {

    enum BACHELORS{
        //i encompass the BIT MASKS for each degree..and then give you the DEGREE MASK for you to trace her DEGREE.

        COMPUTERSCIENCE=01,//first bit for computer science.
            ECE=02, //second bit for electronics and communications.
            EEE=04,//third bit for electrical and electronics..
            MECHANICAL=010,//fourth bit for mechanical..all are from the right..to the left..
            INDUSTRIAL=020,//fifth bit for industrial
            PRODUCTION=040,//sixth bit for production
    }type; //i stop with 6 types..she is 1 among these 6.

};

/*i define the bit mask for extracting the exact degree.convert this mask
  into a bit equivalent..and check the location of the BIT that has 1.
  that is to say,that if the mask is defined as 0x10,which is integer 16,with
  a bit equivalent of ( 1 0 0 0 0 ),then 1 is in the fifth position,thats the
  fifth bit which is ON,and hence,my girl friends degree,is INDUSTRIAL..infact
  this is the simplest to extract,if you check out my bit mask..*/

#define DEGREEMASK (0x4)

//hey thats obvious..havent you guessed it..common..thats too easy.. to guess..I am simply confusing you...

//now i define the progress that she is making..or what she is doing currently..to enable you to guess her current progresses in the field of education..

struct PROGRESS{

    enum PREPARATION{

        MS=01,//the first bit for GRE.i will again enclose a PREPARATION MASK TO reveal her current preparations..

            MBA=02,//second bit for MBA

            MTECH=04,//third bit for MTECH

    }prep; //thats all,I stop with 3..

}; //end of Progress structure..

//the preparation BIT MASK to guess her current prepartion..this is too easy ...common..squeeze me..

#define PREPARATIONMASK 0x1

//now comes the DoB structure..thats the Date of Birth structure for my girl friend..I will reveal her Date of Birth,But again as a Bit Mask..I am playing it safe...Baby..

struct MyGirlFriendsDoB{

    /**********************************************************************
i take 5 bits for the day of birth,as obviously the day of birth cannot be
more than 31..which is 2**5 - 1 or 2 to the power of 5 minus 1,which is 5
BIT ON,or which has the Bit configuration,(1 1 1 1 1),and thats max 5 bits..
similarly i take the max bits for month as 4 as months cannot be greater
than 12,which lies between 8 and 15,thats between 2**3 and 2**4-1,and hence
it takes a max of 4 bits..and for the year i take the remaining,23
bits..that is i am splitting the month,day and year and packing them as a 32

bit entity..this can be done in 'C' using BIT FIELDS..which i have already
used before to encapsulate the number of characters in my girl friends name
as a 'Magic 40 Bit Number'..
    *****************************************************/

    unsigned int month :  4 ;//4 bits for month..

    unsigned int day   :  5; //5 bits for day

    unsigned int year  :  23;
    /*remaining 23 bits,thats the remaining out of a pack of 32 bits..32-(4+5)*/

} ; //end of Date of Birth structure..

//mask for extracting the mm,dd,yy, of my girl friend

#define MONTHMASK (0xF) //4 BIT ON ( 1 1 1 1)
#define DAYMASK   (0x1F) //5 BIT ON ( 1 1 1 1 1)
#define YEARMASK  (0x7FFFFF) //23 BIT ON (1 1 1 ..on so till 23 counts)

#define MY_GIRL_FRIENDS_MONTH_OF_BIRTH (0x6)
#define MY_GIRL_FRIENDS_DAY_OF_BIRTH   (0x12)
#define MY_GIRL_FRIENDS_YEAR_OF_BIRTH  (0x7BA)

/* here i define the elements of the hobby structure of My Girl Friend */
/*
  My girl friends hobby list
*/

struct MyGirlFriendsHobbies {

    //here again i define all her hobbies..this time,there is no BIT MASK ,because,for hobbies,i reckon,i dont need to make you guess..

    enum Hobbies{

        MUSIC= 01, //first bit for MUSIC..only for portability..nothing special

            DANCE= 02, //second bit for DANCE..can be optional.

            MOVIES=04, //third bit for Movies.

            COUCHPOTATO=010, //fourth bit for watching television..

            TALKINGOVERPHONE=020,//fifth bit for telephone talks..she can talk for hours..on the phone..not with me..i cant talk..because of obvious NRE reasons..if i start talking,i will turn bankrupt in a 'jiffy'...
    }hob;

} ; //end of structure for hobbies


struct MyGirlFriendsLikesAndDislikes{

#ifdef MOVIES  //if she likes movies,then this is what she will like

#ifdef HINDI //if she likes hindi movies,than this is the structure for
    hindi movies

    struct HindiFav{
        char favactor[40];
        char favactress[40];
    }hindi;

#define FAVACTORS   "ShahRukhKhanHrithikRoshan" //2 actors embeddeded into 1,offcourse,Hrithik Roshan is my addition.I think she also echoes my like..

#define FAVACTRESSES "KajolAishwaryaMadhuriDixit" //the last heroine was my addition.and i presume she likes her..as much as I..

#elif //if she likes tamil movies..she cant like both Hindi and Tamil..thats my assumption..

    /*I should say,that this portion of the code is not for A.R.KARTHICK.I
      hardly see Tamil Movies..Infact I simply refuse to see Tamil Movies..But if
      Someone..wants me to see...Then I will..provided that Someone has the 'Magic

      Number'associated with the Name..
    */

    struct TamilFav{
        char favactor[40];
        char favactress[40];
    }tamil;

    //Her favorites are the stars of ManiRatnam Directed Film,AliyaPayuthe..I dont like them..I am sorry if i have hurt someone..Only actor,i like in tamil,is KAMAL.HASAN..and MR.RAJNIKANT..to some extent..

#define FAVACTOR    "Madhavan" //tv actor turned tamil actor..
#define FAVACTRESS  "Shalini"  //baby shalini..

#endif


#endif //end outer ifdef for movies

    //covers what she likes generally apart from movies

    enum LIKES {
        HONESTY,//which i presume,i have..or what do you guys feel.
            HARDWORK,//which i do,when the situation demands..
            DEDICATION,//which i have.i am a bit dedicated towards my work.
            SINCERITY,//again,i feel i have..
            SENSEOFHUMOUR, //which i lack..
            FUNLOVING,//which i am not..
            _SIMPLICITY,//which i have...common..squeeze me..if i lack..
            CHILDREN,//thats very much like A.R.KARTHICK
            COMPUTERS,
            /*
              has suddenly developed a sense of liking towards computers..used to hate it
              before..maybe i am responsible for this change in attitude..has also told me
              that she has developed good control over the keyboard..thats a good sign.
            */

    }likes;

    enum DISLIKES {
        HYPOCRITES,//people who pretend what they are not..
            SUPERCILIOUS_ATTITUDE,//over confidence..
            _ARROGANCE,
    }dislikes;

} ; //end of the structure for likes and dislikes..

//the structure which embeds her or 'our' family heritage..
//i declare this structure as a TREE,
//where at the top of the tree,stand the PARENTS,and the branches are occupied by the sons and the daughters..

typedef  char* HEAD_OF_FAMILY;

struct MyGirlFriendsFamily{

    HEAD_OF_FAMILY *head;

    /*she has either a mother or a father..check the PARENTAL BIT MASK to check
      her Parental status..*/

    struct MyGirlFriendsFamily *sonstoleft,*daughterstoright;

    /* this represents a tree,where the sons of my girl friends parents will
       occupy the left branch of the tree,and the daughters will move to the right
       branch..the sons-sons will occupy the right branch of the sons own tree..and
       so on.. The same is for daughters..*/
};

/**Thats the End of all the structure declarations..
   and here comes the Magic Number to crack my girl friends name using the
   tools that I have given...Mere Ko Maaf Karna Yaaron..But I have done My best

   to explain everything about her..and at the same time,retaining the
   technical parlance as an interface to Mask my Girl Friends Intricate
   Details. *****/

/************The MAGIC NUMBER TO CRACK MY GIRL FRIENDS NAME..******
***************The Magic Number is********************

               7 4 1 9 4 6 4 6 5

thats the magic 9 digit number,which has to be converted into its
binary equivalent and split up into a pack of 7 bits.
each pack will represent the binary equivalent of an alphabet of my girl
friends name..i have already enclosed the program for converting this number

into a pack of 7 bits..you can use that tool or the TRCHR[1-5] macros to
extract each character of my girl friend directly and store them into the
string..
That is to say,that if my girl friends name has an alphabet 'a'
embedded in it..then it will have the following bit configuration..in any
one of the 7 Bit Pack..
the binary equivalent of 'a' is ,(i am showing only the top 7 bits..which
make up the alphabet 'a',whose integer ascii value is 97..
bit value of 'a' is ,

                  1 1 0 0 0 0 1

the pack has totally 40 bits..and each pack is made up of 7 bits..
use my tools to crack my girl friends name..and let me know the result..
or Shall I embed the Function which unpacks the Bits from the Number.
Okay Done..
Here comes the Function
*******************************************************/
/* this is the routine to convert the number into bits for your kind persal
 */
/*
  Converts the Magic Number into a 7 Bit Pack,Each Pack being Separated from
  the Other with a 'Hyphon' or '-' symbol..Can be used as a Tool..
  If you want to Skip reading this function,Skip but Please Read On..
*/

char *BitConvert(MyGirlFriendsNameInsideBits magicnumber){

    MyGirlFriendsNameInsideBits i;

    int pos=0;

    static char name[MAX];//contains only bit pack.

    char *str=name;

    MyGirlFriendsNameInsideBits mask;//go through the code for understanding this declaration.

    int counter=0;//for keeping track of the bits..

    //this routines packs the bits of my girl friends name into a string and returns it for your perusal.But I still reckon the usage of TRCHR[1-5] macros to crack my girl friends name.Thats too easy a method..But still unveils some secrets..

    /******
           i start storing the bits from the most significant position,thats extreme
           right position to enable readability.There are only 40 bits in my girl
           friends Name to be stored..into a pack of 7 bits..so thats 5 packs..and
           hence my girl friends name contains 5 characters..
    *****/

    for(i=CONSTANT-1;i>=0;i--){

        mask=((MyGirlFriendsNameInsideBits) 1 << i); //check the status of the ith BIT.

        if ( (magicnumber & mask) == 0)
            str[counter]='0';
        else
            str[counter]='1';

        counter++; //increment the counter

        if( pos==7 && i)
            //            counter != 0x27)
        {
            str[counter]='-';
            counter++;
            pos=0;
            continue;
        }
        pos++;

    } //end for

    str[counter]='\0'; //null terminate the Bit Padded string..

    return name;//return the Bit Packed Name for your kind perusal..
}

/*
  At the Worst scenario,you can simply copy this entire mail,into any 'C'
  editor,and compile the code with a call only to the
  'Check_Everything_About_My_GirlFriend function,with my girl friends Magic
  Number as a Function Argument.
  You have to remove some other Function Calls from the 'main' Function and
  just invoke the 'Check_Everything_About_My_GirlFriend' function with the
  Magic Number of My Girl Friend as a Function Argument.
  Define your 'main' function like this.

  main(){
  Check_Everything_About_My_GirlFriend((MyGirlFriendsNameInsideBits)
  353282312257);
  exit(0);
  } //thats the only change you have to Make to my code,and copy everything
  else from this mail with the original 'main' function in my code,replaced by

  the above. And Then Compile...

  .I have ran the code in my Linux Box at my home with 'gcc' compiler ,and it
  worked fine giving me the desired output.If you want to run it in TurBO C Or

  any WIN 32 DEBUGGER,then please check for the usage of the  '__extension__'
  keyword in my code.See whether it works..If it Doesnt,then omit the keyword
  and ReCompile the Code.You will definitely get the Output related to My girl

  Friend.
*/
/*****I hope LOVEBIRDS can use this tool to keep everyone guessing about
      their beloveds name..But this Mail was Serious..

      I have put in so much of effort to explain each and every bit of the Mail
      that I am driven by fatigue..The Day of Composing This Mail was 'Saturday'
      and the time of 'wrap up' was 10:40 PM EST,(European Standard Time),Location

      - 'My Room,in Kringsja' and System-'My Favorite Compaq Pentium 60 Mhz.'
      which has always assisted me in India and Now continuing its Loyalty in
      Oslo.

      I was yet to take off for my Supper..My Stomach was beckoning me..I had to
      Leave..I was 'Hungry'..
      Remember,You have to crack my girl friends name,using the tools I have
      presented.
      I wont disclose her Name from my mouth,even if you ask me about it.
      I am not Joking.I am serious.

      Please Understand My Emotions..and try to Make them Compatible with your
      Attitude..

      Its An Earnest Request Made from My Heart..

      The Above Mail proves that 'Language is Only an Expression' to convey Ones
      feelings.One can resort to any language,as long as he is able to convey his
      emotions in his own 'Inimitable Style'.

      With Love,

      A.R.KARTHICK signing out from his 'House Computer' at Kringsja on
      Saturday,the 7th of Oct..10:40 PM EST.
      Editor Used to Compose the Mail:
      Famous "VI" editor of LINUX,KERNEL 2.2.5-15.0. running on a 'COMPAQ 60
      MHZ,CPU FAMILY 586' at A.R.KARTHICKs RESIDENCE at KRINGSJA STUDENTBY,OSLO.
      Location of Mail in A.R.KARTHICKs Residence Computer:
      File Name:/home/karthick/${MyGirlFriendsName}/test.c and
      /home/karthick/${MyGirlFriendsName}/extern.c
      where ${MyGirlFriendsName} contains my girl friends name.
      Mounted on: /dev/hda5.
      Compiler Used to Parse the Code: Richard Stallmans,Famous "GCC" compiler.
      Personal Favorites in 'The Computer Field':

      1) Linus Torvalds(Finland)-Writer of the Linux Kernel.Exceptional
      Programmer.A Programmer Par Excellence.Started Learning 'Unix and C' in
      1990,when he was 21 years of Age at the Finnish University,and started
      writing the Linux Kernel,in the Spring of 1991.'Gods Gift to the Field of
      Computers'.
      2) Alan Cox(Wales)-Undisputed King of Device Drivers,The Original 3COM
      Hacker(Ethernet card (Network) drivers).
      A Computer Geek who has Played an Equal Role in the Shaping of the Linux
      Kernel.Number 1 Programmer according to Linus Torvalds.Was the First to
      Introduce SMP (Symmetric Multi Processing Support) for LINUX.
      Check out the 'TRANSMETA' (www.transmeta.com) product,named 'ALAN COX ON A
      CHIP'.If 'Others Fail' to solve your Problem,then ask 'Alan Cox'.He will fix

      it in no time.
      3) Richard Stallman(US OF A)-Top Class Programmer.Responsible for the GCC
      compiler,GDB debugger,and a whole lot of Other utilities.Has also programmed

      Operating Systems.Highly Reputed and Heads the OSF.(Open Source
      Foundation).Regards the Compiler as a Far More Important Component of the
      OPERATING SYSTEM than the Kernel.
      4) Tsutomu Shimomura(Japan)-San-Diego,Super Computer Security Expert.A
      Computer Wiz,Who can Program at the Speed of Light.A Hackers Nightmare.
      Check out the site www.takedown.com to know more about his intrustion
      detection Ingenuity.
***********/


