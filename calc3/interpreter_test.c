#include "ctap.h"
#include <string.h>
#include "tokenizer.c"
#include "interpreter.c"
TESTS {
	interpret();
	FILE *fp = NULL;
	fp = fopen("code.txt", "w"); //overwrite code.txt to be NULL
	ok((fp!=NULL) && (stdout !=NULL), "code.txt isn't NULL and so neither is stdout");
	fclose(fp);		
	
}