#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

#include "merge_sort.h"
/*
int main ()
{
    int arr_size = 0;
    
    if (!(scanf ("%d", &arr_size)))
    {
        return -1;
    }

    uint32_t *arr = (uint32_t *)calloc (arr_size, sizeof (uint32_t));
    assert (arr);

    for (int idx = 0; idx < arr_size; idx++)
    {
        if (!(scanf ("%d", arr + idx)))
        {
            return -1;
        }
    }

    uint32_t *array = merge_sort (arr, arr_size);

    for (int idx = 0; idx < arr_size; idx++)
    {
        printf ("%d ", *(array + idx));
    }
    
    free (array);
    free (arr);

    
    return 0;
}*/

uint32_t *merge_sort (uint32_t * arr, int size)
{
    return merge_sort_ (arr, 0, size - 1);
}

uint32_t *merge_sort_ (uint32_t *arr, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    if (start == end)
    {
        uint32_t *array = (uint32_t *)calloc (1, sizeof (uint32_t));
        *array = arr[start];
        return array;
    }

    int mid = start + (end - start)/2;

    uint32_t *left = merge_sort_ (arr, start, mid);
    uint32_t *right = merge_sort_ (arr, mid + 1, end);

    uint32_t *array = (uint32_t *)calloc (end - start + 1, sizeof (uint32_t));

    int idx = 0;
    int i = 0;
    int j = 0;
    
    while (i <= mid - start || j <= end - mid - 1)
    {
        if (i <= mid - start && (j > end - mid - 1 || left[i] < right[j]))
        {
            array[idx] = left[i];
            idx++;
            i++;
        }
        else
        {
            array[idx] = right[j];
            idx++;
            j++;
        }
    }


    free (left);
    free (right);

    return array;
}   