#ifndef QUICK_SORT_H
#define QUICK_SORT_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>

void swap_uint32 (uint32_t *val1, uint32_t *val2);
void quick_sort (uint32_t *arr, int size, int (*find_pivot)(uint32_t *arr, int start, int end, int shift));
void quick_sort_ (uint32_t *arr, int start, int end, int (*find_pivot)(uint32_t *arr, int start, int end, int shift));
void bubble_sort (uint32_t *arr, int start, int end, int shift);
int hoar_partition (uint32_t *arr, int pivot, int start, int end);
int median_of_medians (uint32_t *arr, int start, int end, int shift);
int median_of_three (uint32_t *arr, int start, int end, int shift);
int central (uint32_t *arr, int start, int end, int shift);
int rand_pivot (uint32_t *arr, int start, int end, int shift);

#endif /* QUICK_SORT_H */