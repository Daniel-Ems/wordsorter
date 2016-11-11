#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

int length_sort(const void *a, const void *b);

int lexi_sort(const void *a, const void *b);

char *get_words(char *token);

void print_reverse(char **tmp_hope, int last_idx, int print_limit);

void print_unique(char **tmp_hope, int last_idx, int print_limit);

#endif
