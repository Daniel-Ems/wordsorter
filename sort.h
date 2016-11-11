#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdbool.h>

char *get_words(char *token);

int length_sort(const void *a, const void *b);

int lexi_sort(const void *a, const void *b);

void print_reverse(char **tmp_hope, int last_idx, int print_limit, bool unique);

//void print_unique(char **tmp_hope, int last_idx, int print_limit);

void print_lexi(char **tmp_hope, int print_limit);

#endif

