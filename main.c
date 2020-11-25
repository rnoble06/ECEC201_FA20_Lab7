#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Your code goes here! */

    /* --------------------------
       +- reads lorum.txt
       +- counts number of characters on each line
       +- creates a file count.txt 
       +- count.txt contains character count for       each line
       +- format for count.txt
          - linenumber: character_count
       +- character count for a line should NOT include   newline character, /n 
       ---------------------------*/


/* open file */
FILE *fp1;
FILE *fp2;
int char_count = 0;
int linenumber = 1;
int c;

fp1 = fopen("lorum.txt","r");
fp2 = fopen("count.txt","w");

if(fp1 == NULL)
{
  fprintf(stderr, "Failed to open file\n");
  return EXIT_FAILURE;
}

while ((c=fgetc(fp1)) != EOF)
{
  if (c == '\n')
  {
    char_count --;
    fprintf(fp2,"%d: %d\n",linenumber, char_count);
    linenumber ++;
    char_count = 0;
  }
  char_count++;
}
fprintf(fp2,"%d: %d\n",linenumber, char_count-1);
    return 0;
}