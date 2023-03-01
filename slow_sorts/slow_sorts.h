#ifndef SLOW_SORT_H
#define SLOW_SORT_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void swap_int32 (uint32_t *val1, uint32_t *val2);
void bubble_sort (uint32_t *arr, int size);
void insert_sort (uint32_t *arr, int size);
void select_sort (uint32_t *arr, int size);
void print_arr (uint32_t *arr, int size);

#endif /* SLOW_SORT_H */