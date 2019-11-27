/*
    infixtopostfix.h
    Tingting Xun
    26 November 2019
*/

#include "tokenizer.h"

/* function to read char by char from file and return single value*/
char readchar(FILE *myfile){
	char c = getc(myfile);
	return c;
}

/* define operator checker */
int is_operator(char symbol)
{
	if(symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-' || symbol == '^' || symbol == '%')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

/*-------------------------------------------------------------------------
	evaluate the next token, nt, to generate the appropriate code to output
---------------------------------------------------------------------------*/
void code_cases(char pt, char nt, FILE *myfile, FILE *newfile) {	//pt=prev_token  and  nt=new_token
	switch(nt) {

		case '*': fputs("MUL", newfile);
		break;

		case '/': fputs("DIV", newfile);
		break;

		case '-': fputs("SUB", newfile);
		break;

		case '+': fputs("ADD", newfile);
		break;

		case '^': fputs("EXP", newfile);
		break;

		case '%': fputs("mod", newfile);
		break;
            
        case '.': fputs(".", newfile);
        break;

		case ' ': fputs("\n", newfile);
		break;

		default:
			if(isdigit(nt)) {			//check if the token is an integer between 0 and 9
				if(isdigit(pt)||pt=='.') { 		//check previous token(pt) to see if the new token(nt) is part of multidigit integer
					fputc(nt, newfile);	//new token is appended without the string "LOADINT   "
					break;
				}

				char str[] = "LOADNUM  ";
				str[8] = nt;			//8 is the index of str[] representing integer inputs

				fputs(str, newfile);
				break;
			}
			else{
				fputs("erroneous input detected", newfile);
			}
	}

}

// test
void testtokenizer(){
	FILE *fp = NULL;
	
	fp = fopen("infix.txt", "r");
	if ( fp == NULL) {
		fprintf(stderr, "File does not exist.\n");
		exit(1);
	}
	char c = readchar(fp);
}