#include "sort.h"


int lexi_sort(const void *a, const void *b)
{
	return strcmp(*(const char**) a, *(const char**)b);
}

int length_sort(const void *a, const void *b)
{
	return strlen(*(const char**) a) - strlen( *(const char**)b);
}


	//the inner four loop is compliment of Alexander Dow.
void print_unique(char **tmp_hope, int last_idx, int print_limit)
{
		int b = 0;
		for(int i = 0; i < print_limit; i++){
		int count = 0;
			for(b=(i+1); b < last_idx; b++){
				if(!strcmp(tmp_hope[i],tmp_hope[b])){
					count++;
				}
			}
		if(count == 0){
			printf("%s\n", tmp_hope[i]);
			}
		}
}

char *get_words(char *token)
{
			char buf[36];
			size_t words_length = sizeof(buf) + 1;

			char *words = malloc(words_length);
			if(!words){
				return 0;
			}

			strncpy(words, token, words_length);

			//tmp_hope[last_idx - 1] = words;
			//printf("%s\n", tmp_hope[last_idx - 1]);
		//char *free_me = words;
		return words;
}
