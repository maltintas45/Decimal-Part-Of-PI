#ifndef _H
#define _H
#include <stdio.h>

#define ARRAY_SIZE 100

#include "token.h"

struct Counter{
	Token token_array[ARRAY_SIZE];
	int token_count=0;
	bool contains(char *,char);
	int findindex(Token [],char[]);
	Token *get_most_common_three();
	void read_and_count();
};
#endif
