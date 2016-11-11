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
	char **tmp_hope = malloc((1+last_idx) * sizeof(tmp_hope));
	tmp_hope[0] = NULL;
	char tmp_buf[64];
	char *words;
	char *token;
	void *tmp_buffer;
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
			tmp_buffer = realloc(tmp_hope, sizeof(tmp_hope) *(1 + last_idx));
			if(!tmp_buffer){
				printf("unable to realloc");
			}

			tmp_hope = tmp_buffer;

			tmp_hope[last_idx] = NULL;

			words = get_words(token);

			tmp_hope[last_idx - 1] = words;

			token = strtok(NULL, " \n");
		}
	}

	fclose(first);

	}while(argc> optind);

	qsort(tmp_hope, last_idx, sizeof(char *), sort_func);

	
	if(print_limit == 0){
		print_limit = last_idx;
	}

	//if(unique){
	//	print_unique(tmp_hope, last_idx, print_limit);
	//}
	puts("\n");
	if(reverse){
		print_reverse(tmp_hope, last_idx, print_limit, unique);
	}else{
		print_lexi(tmp_hope, print_limit);
	}
		

		char **word_list = tmp_hope;
		while(*word_list){
			//printf("%s\n", *word_list);
			free(*word_list);
			++word_list;
		}

	free(tmp_hope);

	}






