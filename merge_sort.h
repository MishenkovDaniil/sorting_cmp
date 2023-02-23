#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t *merge_sort (uint32_t * arr, int size);
uint32_t *merge_sort_ (uint32_t *arr, int start, int end);

#endif /* MERGE_SORT_H */