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
	char *
	opterr;

	int command_arguments;
	while (-1 < (command_arguments = getopt(argc, argv, "rnlsauhc:"))){
		switch(command_arguments){
			case 'r':
				//TODO: program prints in reverse
				printf("-r\n");
				break;
			case 'n':
				//TODO: sorts as if they were numbers
				printf("-n\n");
				break;
			case 'l':
				//TODO: sorts the words by length
				printf("-l\n");
				break;
			case 's':
				//TODO: sorts words by scrabble score
				printf("-s\n");
				break;
			case 'a':
				//TODO: sorts lexicographically
				printf("-a\n");
				break;
			case 'u':
				//TODO: only prints unique words, case sensitive
				printf("-u\n");
				break;
			case 'h':
				//TODO: prints brief help message of any normal operation.
				printf("-h\n");
				break;
			case 'c':
				//TODO: prints number passed results
				partial_results = strtol(optarg,NULL,10);
				printf(" number of words in list %d\n", partial_results);
				break; 
			default:
				//printf("Default option handler got %c\n", command_arguments);
				break;
		}
	}

	char *tmp_hope[256];
	char tmp_buf[256];
	char *b;
	char *c;
	int i =0;
	if(optind != argc){
		FILE *first = fopen(argv[optind], "r");
		while(fgets(tmp_buf, sizeof(tmp_buf), first) !=NULL){
			b = tmp_buf;
			while(1){
				c = strtok(b, " \n");
				b = NULL;
				if(c ==NULL){
					break;
				}
				tmp_hope[i++] = c;
				printf("%s\n", c);
			}
		}
	}
}
