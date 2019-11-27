/*
    infixtopostfix.h
    Tingting Xun
    26 November 2019
*/

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>
#include<stdlib.h> /* for exit() */
#include <assert.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>

	char readchar(FILE *myfile);
	int  is_operator(char symbol);
	int  precedence(char symbol);
	void code_cases(char pt, char nt, FILE *myfile, FILE *newfile);

#endif