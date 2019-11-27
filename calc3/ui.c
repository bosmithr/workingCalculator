#include <stdio.h>
#include <stdlib.h> 
#include "infixtopostfix.h"
#include "codegen.h"
#include "interpreter.h"

int main()
{
	FILE *output = fopen("infix.txt", "w");
	char buf[500]; 
    fgets(buf, 500, stdin); 
    printf("input: %s\n", buf); 
    fputs(buf, output);
    fclose(output);
	
	testinfixtopostfix();

	codegen();
	
	interpret();
}