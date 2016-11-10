#define _XOPEN_SOURCE
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sysexits.h>
#include <string.h>  //may not need
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

	int partial_results = 0;
	opterr = 0;

	int command_arguments;
	while (-1 < (command_arguments = getopt(argc, argv, "rnlsauhc:"))){
		switch(command_arguments){
			case 'r':
				//TODO: program prints in reverse
				//printf("-r\n");
				break;
			case 'n':
				//TODO: sorts as if they were numbers
				//printf("-n\n");
				break;
			case 'l':
				//TODO: sorts the words by length
				printf("-l\n");
				break;
			case 's':
				//TODO: sorts words by scrabble score
				//printf("-s\n");
				break;
			case 'a':
				//TODO: sorts lexicographically
				//printf("-a\n");
				break;
			case 'u':
				//TODO: only prints unique words, case sensitive
				//printf("-u\n");
				break;
			case 'h':
				//TODO: prints brief help message of any normal operation.
				//printf("-h\n");
				break;
			case 'c':
				//TODO: prints number passed results
				partial_results = strtol(optarg,NULL,10);
				printf(" number of words in list %d\n", partial_results);
				break; 
			default:
				printf("Default option handler got %c\n", command_arguments);
				break;
		}
	}


	size_t last_idx =0;
	char **tmp_hope = malloc((1+last_idx) * sizeof(tmp_hope));
	tmp_hope[0] = NULL;
	char tmp_buf[64];

	char *token;
	FILE *first;
	if(optind != argc){
		first = fopen(argv[optind], "r");
	}
	while(fgets(tmp_buf, sizeof(tmp_buf), first)){
		token = strtok(tmp_buf, " \n");
		while(token){

			++last_idx;

			void *tmp_buffer = realloc(tmp_hope, sizeof(*tmp_hope) *(1 + last_idx));
			if(!tmp_buffer){
				printf("unable to realloc");
			}
			tmp_hope = tmp_buffer;

			tmp_hope[last_idx] = NULL;

			if(token ==NULL){
				break;
			}

			tmp_hope[last_idx - 1] = token;
			printf("%s\n", tmp_hope[last_idx - 1]);
			
			token = strtok(NULL, " \n");
			//free(tmp_);
		}
	}
	printf("%s\n", *tmp_hope);
	fclose(first);
	free(tmp_hope);

}
