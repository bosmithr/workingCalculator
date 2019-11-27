#include "ctap.h"
#include <string.h>
#include "tokenizer.c"
TESTS {

	//test file for tests consists of: "1*/-+^%. "
	FILE *test_read = NULL; 			
	FILE *test_write = NULL;	
	
	//readchar
	test_read = fopen("test_read.txt", "r");
	ok(readchar(test_read) == '1', "\tread token from test file");
	fclose(test_read);


	//is_operator   should check if token is an operator
	ok(is_operator('%') == 1, "\t%% symbol is an operator");



	//code_cases	should check the correct symbol to be read then write the code for that symbol to a file
	//MUL
	char buf[4]; 
	test_read = fopen("test_read.txt", "r");
	test_write = fopen("test_write.txt", "w");
	code_cases(' ', '*', test_read, test_write);
	fclose(test_write);
	fclose(test_read);
	test_write = fopen("test_write.txt", "r");
    fgets(buf, 4, test_write); 
	ok(strcmp(buf,"MUL")==0, "\t'*' is the next token and 'MUL' is the next code written"); 
  	fclose(test_write);

	//DIV
	test_read = fopen("test_read.txt", "r");
	test_write = fopen("test_write.txt", "w");
	code_cases(' ', '/', test_read, test_write);
	fclose(test_write);
	fclose(test_read);
	test_write = fopen("test_write.txt", "r");
    fgets(buf, 4, test_write); 
	ok(strcmp(buf,"DIV")==0, "\t'/' is the next token and 'DIV' is the next code written"); 
  	fclose(test_write);
	
	//SUB
	test_read = fopen("test_read.txt", "r");
	test_write = fopen("test_write.txt", "w");
	code_cases(' ', '-', test_read, test_write);
	fclose(test_write);
	fclose(test_read);
	test_write = fopen("test_write.txt", "r");
    fgets(buf, 4, test_write); 
	ok(strcmp(buf,"SUB")==0, "\t'-' is the next token and 'SUB' is the next code written"); 
  	fclose(test_write);

  	//ADD
	test_read = fopen("test_read.txt", "r");
	test_write = fopen("test_write.txt", "w");
	code_cases(' ', '+', test_read, test_write);
	fclose(test_write);
	fclose(test_read);
	test_write = fopen("test_write.txt", "r");
    fgets(buf, 4, test_write); 
	ok(strcmp(buf,"ADD")==0, "\t'+' is the next token and 'ADD' is the next code written"); 
  	fclose(test_write);

  	//EXP
	test_read = fopen("test_read.txt", "r");
	test_write = fopen("test_write.txt", "w");
	code_cases(' ', '^', test_read, test_write);
	fclose(test_write);
	fclose(test_read);
	test_write = fopen("test_write.txt", "r");
    fgets(buf, 4, test_write); 
	ok(strcmp(buf,"EXP")==0, "\t'^' is the next token and 'EXP' is the next code written"); 
  	fclose(test_write);

	//mod
	test_read = fopen("test_read.txt", "r");
	test_write = fopen("test_write.txt", "w");
	code_cases(' ', '%', test_read, test_write);
	fclose(test_write);
	fclose(test_read);
	test_write = fopen("test_write.txt", "r");
    fgets(buf, 4, test_write); 
	ok(strcmp(buf,"mod")==0, "\t'%%' is the next token and 'mod' is the next code written"); 
  	fclose(test_write);

	//decimal point
	test_read = fopen("test_read.txt", "r");
	test_write = fopen("test_write.txt", "w");
	code_cases(' ', '.', test_read, test_write);
	fclose(test_write);
	fclose(test_read);
	test_write = fopen("test_write.txt", "r");
    fgets(buf, 4, test_write); 
	ok(strcmp(buf,".")==0, "\t'.' is the next token and a decimal is the next code written"); 
  	fclose(test_write);

  	//space
	test_read = fopen("test_read.txt", "r");
	test_write = fopen("test_write.txt", "w");
	code_cases(' ', ' ', test_read, test_write);
	fclose(test_write);
	fclose(test_read);
	test_write = fopen("test_write.txt", "r");
    fgets(buf, 4, test_write); 
	ok(strcmp(buf,"\n")==0, "' ' is the next token and a new line is the next code written"); 
  	fclose(test_write);


    //ok(readchar(test_write) == '1', "correct M");
	//code_cases(' ', '*', test_read, test_write);

	//ok(buf[0] == 'M', "\t'*' is the next token and 'MUL' is the next code written");


}