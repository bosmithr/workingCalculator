/*
    infix2postfix.h
    Tingting Xun
    24 November 2019
*/
#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include <stdio.h>
#include <stdlib.h> /* for exit() */
#include <assert.h>
#include <ctype.h> /* for isdigit(char ) */
#include "tokenizer.h"

#define SIZE 100
	
	void push(char item);
	char pop();
	void writechar(FILE *newfile, char c);
	int precedence(char symbol);
	void infix2postfix(FILE *myfile, FILE *newfile);
	void testinfixtopostfix();

#endif