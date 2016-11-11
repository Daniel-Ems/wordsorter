#include "sort.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum{LONGEST_WORD = 36};

// Referencing our movie_titler from class.
char *get_words(char *token)
{
	char buf[LONGEST_WORD];
	size_t words_length = sizeof(buf) + 1;

	char *words = malloc(words_length);
	if(!words){
		return 0;
	}
	strncpy(words, token, words_length);

	return words;
}

int lexi_sort(const void *a, const void *b)
{
	return strcmp(*(const char**) a, *(const char**)b);
}

int length_sort(const void *a, const void *b)
{
	return strlen(*(const char**) a) - strlen( *(const char**)b);
}

// Alexander Dow helped me with solving the "unque" part of the inner loop.  
void print_reverse(char **word_list, int last_idx, int print_limit, bool unique)
{
	for(int i = (last_idx - 1); i >= last_idx - print_limit; i--){
		int count = 0;
		for(int b=(i - 1); b > 0; b--){
			if(unique == true && !strcmp(word_list[i],word_list[b])){
				count++;
			}
		}
		if(count == 0){
			printf("%s\n", word_list[i]);
		}
	}
}


void print_lexi(char **word_list, int print_limit, int last_idx, bool unique)
{
	for(int i = 0; i < print_limit; i++){
		int count = 0;
		for(int b=(i+1) ; b < last_idx; b++){
			if(unique == true && !strcmp(word_list[i],word_list[b])){
				count++;
			}
		}
		if(count == 0){
			printf("%s\n", word_list[i]);
		}
	}
}







