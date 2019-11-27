/*
    infix2postfix.c
    Tingting Xun
    24 November 2019
*/

#include "infixtopostfix.h"

char stack[SIZE];
int top = 0;

/* define push operation */
void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

/* define pop operation */
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

/* define write char to file function */
void writechar(FILE *newfile, char c){
	fputc(c, newfile);
}

/* define fucntion that is used to assign precendence to operator.
 * higher integer value means higher precendence */
int precedence(char symbol)
{
	if(symbol == '^'){
		return(3);
	}
	else if(symbol == '*' || symbol == '/' || symbol == '%')			/* highest precedence*/
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')     /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

/* define function to convert infix to postfix */
void infix2postfix(FILE *myfile, FILE *newfile){

	char stack_top;
	char item;
	char prev_item;
	
	item = readchar(myfile); // read character from file use tokenizer
	prev_item = item;
	
	while(!feof(myfile))        				/* run loop till end of infix expression */
	{
		switch(item){
		
			case '(': 	push(item);break;
			
			case ')': 
						stack_top = pop();                   /* pop and keep popping until */
						while(stack_top != '(')                /* '(' encounterd */
						{
							writechar(newfile, ' ');
							writechar(newfile, stack_top);
							stack_top = pop();
						}
						break;
			
			case '.': 	writechar(newfile, item);break;
			
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '%':
						stack_top = pop();
						while(is_operator(stack_top) == 1 && precedence(stack_top)>= precedence(item))
						{                 
							writechar(newfile, ' ');
							writechar(newfile, stack_top); /* so pop all higher precendence operator and */
							stack_top = pop();                       /* add them to postfix expresion */
						}
						push(stack_top); 			/* push the operator does not match the while back to the stack*/
						push(item);                 /* push current operator symbol onto stack */
						break;
						
			case ' ':break;
			default:
					if(isdigit(item)){
						if(!isdigit(prev_item) && prev_item != '.'){/* add space while previous item is not integer or float */
							writechar(newfile, ' ');
						}
					writechar(newfile, item);  			/* add operand symbol to postfix expr */
					}
			} /* switch end here*/
		
		prev_item = item;
		item = readchar(myfile); /* go to next symbol of infix expression */
	} /* while loop ends here */
	
	if(item == EOF){
		stack_top = pop(); 							// pop all from stack
		while(top != -1)   
			{
				writechar(newfile, ' ');
				writechar(newfile, stack_top);
				stack_top = pop();
			}
	}
}

// Test
void testinfixtopostfix(){

	FILE *fp = NULL;
	
	fp = fopen("infix.txt", "r");
	
	if ( fp == NULL) {
		fprintf(stderr, "File %s does not exist.\n", "infix.txt");
		exit(1);
	}
	
	FILE *output = fopen("postfix.txt", "w");
	assert(fp != NULL);// will terminate the program if its argument turns out to be false. 
	
	infix2postfix(fp, output);

	fclose(fp);
	fclose(output);
}
/*
int main(int argc, char **argv){
	testinfixtopostfix();
	return 0;
}
*/
