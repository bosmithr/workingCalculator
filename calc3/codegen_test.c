#include "ctap.h"
#include "tokenizer.c"
#include "codegen.c"

TESTS
{
	FILE *fp = NULL;
	fp = fopen("code.txt", "w"); //overwrite code.txt to be NULL
	fclose(fp);					 //close file


    codegen();					 //load code.txt with codes converted from postfix
    
    FILE *fp1 = NULL;			 //create new FILE to check if postfix.txt is NULL
    fp1 = fopen("postfix.txt", "r"); //postfix.txt can potentially have leftover data
	FILE *fp2 = NULL;
   	fp2 = fopen("code.txt", "r"); //code.txt is to be checked for data
   	if (fp1==NULL && fp2==NULL) pass("postfix.txt and code.txt are both NULL");
   	if (fp1==NULL && fp2!=NULL) fail("code.txt was loaded with unexpected input");
  	ok((fp1!=NULL && fp2!=NULL), 	 "code.txt and postfix.txt not null");
   	fclose(fp1);
   	fclose(fp2);
}
