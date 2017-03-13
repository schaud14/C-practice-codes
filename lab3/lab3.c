#include <stdio.h>
#include <string.h>
/* Defining Macros */
#define EQUALS ==
#define TRUE 1
#define FALSE 0
/*--------- Debug for printing if matched -------*/
#if TRUE
#define TRACE  fprintf(stderr, "Line no is: %d \n", __LINE__)
#define DEBUG(x,y,n,z) fprintf(stderr, " The Haystack Given is : %s\n The Needle is : %s\n The Needle Found at Location %d\n The Buffer is : %s\n ",haystack,needle,loc+1,buffer);
#else
#define TRACE
#define DEBUG(z)
#endif
#define LOCC fprintf(stderr, "Needle not present in Haystack\n");
#define DEBUGSTR(x) if (x==TRUE)fprintf(stderr, "Enter Haystack: "); else fprintf(stderr, "Enter Needle: ");

/*---------- MAIN CODE --------*/

#define CODE(x,y) loc = search(haystack, needle); \
   if (loc EQUALS -1){\
      LOCC;\
      TRACE;}\
   else\
      {\
      printstr(haystack ,needle,loc);\
      DEBUG(haystack ,needle, loc,buffer);\
      TRACE;\
      }\



char buffer[50];

/*-------  Adding buffer array if match is found --------*/

void printstr(char haystack[], char needle[], int loc)
{
int ln=strlen(needle);
int ii;
   memset(buffer, 0, strlen(buffer));
   for (ii=0;ii<ln;ii++)
   {
      buffer[ii]=haystack[loc];
      loc++;
   }
}
 
   
/* ---------Function for searching the needle in haystack ----------*/

int search(char haystack[], char needle[]) 
{
   int haystack_len, needle_len, firstMatch;
   haystack_len = 0, needle_len = 0;
   
   while (haystack[haystack_len] != '\0') 
   {
 
      while (haystack[haystack_len] != needle[0] && haystack[haystack_len] != '\0')
         haystack_len++;
 
      if (haystack[haystack_len] EQUALS '\0')
         return (-1);
 
      firstMatch = haystack_len;
 
      while (haystack[haystack_len] EQUALS needle[needle_len] && haystack[haystack_len] != '\0' && needle[needle_len] != '\0') {
      //buffer[needle_len]=haystack[haystack_len];
         haystack_len++;
         needle_len++;
      
      }
 
      if (needle[needle_len] EQUALS '\0')
         return (firstMatch);
      if (haystack[haystack_len] EQUALS '\0')
         return (-1);
      
      haystack_len = firstMatch + 1;
      needle_len = 0;
   }
  
}

/* ------- Main Function Containning only Macros ---------*/ 
int main() 
{
   int loc;
   char haystack[] = "Good Morning";
   char needle[] = "od Morn";
   CODE(haystack,needle);
   memset(haystack, 0, strlen(haystack));
   memset(needle, 0, strlen(needle));
   DEBUGSTR(TRUE);
   scanf("%s",&haystack);
   DEBUGSTR(FALSE);
   scanf("%s",&needle);
   CODE(haystack,needle);
   return (0);
}