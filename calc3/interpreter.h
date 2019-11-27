#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h> /* for exit() */
#include <assert.h>
#include <ctype.h> /* for isdigit(char ) */
#include <math.h>
#include "tokenizer.h"

	char readchars(FILE *myfile);
	void interpret();

#endif