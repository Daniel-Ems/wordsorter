#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sysexits.h>
#include <string.h>  //may not need
#include <stdlib.h>
#include <ctype.h>

#include "sort.h"


int main(int argc, char *argv[])
{

	opterr = 0;

	int print_limit = 0;

	bool unique = false;
	bool reverse = false;

	int (*sort_func)(const void *a, const void *b) = &lexi_sort;

	// Referncing movie_titler from class
	int command_arguments;
	while (-1 < (command_arguments = getopt(argc, argv, "rnlsauhc:"))){

		switch(command_arguments){

			case 'r':
				reverse = true;
				break;
			case 'n':
				//TODO: sorts as if they were numbers
				//printf("-n\n");
				break;
			case 'l':
				sort_func =  &length_sort;
				break;
			case 's':
				//TODO: sorts words by scrabble score
				//printf("-s\n");
				break;
			case 'a':
				sort_func = &lexi_sort;
				break;
			case 'u':
				unique = true;
				break;
			case 'h':
				printf("Usage: [-r <Reverse results>] [-n < As Number's>]"
								"[-l <By Length>] [-s <Scrabble score>]"
								"[-a <Lexicographically>] [-u <Unique words>]"
								"[ -c: <insert number>]\n");
				return EX_USAGE;
			case 'c':
				print_limit = strtol(optarg,NULL,10);
				break; 
			default:
				printf("We were unable to process your request\n");
				return EX_USAGE;
				break;
		}
	}

	int last_idx =0;
	char **word_list = malloc((1+last_idx) * sizeof(word_list));
	word_list[0] = NULL;
	char tmp_buf[64];
	char *words;
	char *token;
	void *realloc_buffer;
	FILE *first;

do{
	if(optind != argc){
		first = fopen(argv[optind], "r");
	}else{
		first = stdin;
	}

	++optind;
	while(fgets(tmp_buf, 64, first)){

		token = strtok(tmp_buf, " \n");

		while(token){

			if(token == NULL){
				break;
			}

			++last_idx;
			realloc_buffer = realloc(word_list, sizeof(word_list) *(1 + last_idx));

			// Reference Liam and his awesomeness.
			if(!realloc_buffer){
				printf("unable to realloc");
			}

			word_list = realloc_buffer;

			word_list[last_idx] = NULL;

			words = get_words(token);

			word_list[last_idx - 1] = words;

			token = strtok(NULL, " \n");
		}
	}

	fclose(first);

	}while(argc> optind);

	qsort(word_list, last_idx, sizeof(char *), sort_func);

	if(print_limit == 0){
		print_limit = last_idx;
	}

	puts("\n");
	if(reverse){
		print_reverse(word_list, last_idx, print_limit, unique);
	}else{
		print_lexi(word_list, print_limit,last_idx, unique);
	}

		char **free_buffer = word_list;
		while(*free_buffer){
			free(*free_buffer);
			++free_buffer;
		}

	free(word_list);

	}






