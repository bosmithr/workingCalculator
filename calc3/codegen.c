/*
    Codegen.c
    Kevin Smith
    11 November 2019
*/
#include "codegen.h"

void codegen() {
	FILE *fp = NULL; 				//File for reading input
	fp = fopen("postfix.txt", "r"); //open and read the Infix2Postfix output file "postfix.txt"

	if (fp == NULL) {
		fprintf(stderr, "File %s does not exist.\n", "postfix.txt");
		FILE *output = fopen("code.txt", "w"); 	//write blank file to output: code.txt
		return;
	}

	char prev_token = ' ';					//keep track of the previous token for multidigit inputs 
	char next_token = readchar(fp); 		//dynamic variable used to hold value of each subsequent token
	
	FILE *output = fopen("code.txt", "w"); 	//File where the generated code is written

	while (!feof(fp)) {							//examine each token until the next token is 'eof'
		code_cases(prev_token, next_token, fp, output); 
		prev_token = next_token;
		next_token = readchar(fp);
	}
	
	char c = readchar(fp);

	fclose(fp);
	fclose(output);
}
/*
int main()
{
	codegen();
	return 0;
}
*/


