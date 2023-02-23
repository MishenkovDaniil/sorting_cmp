#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdint.h>

#include "quick_sort.h"

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

    //quick_sort (arr, arr_size, median_of_medians);
    //quick_sort (arr, arr_size, median_of_three);
    //quick_sort (arr, arr_size, central);
    quick_sort (arr, arr_size, rand_pivot);
    
    for (int idx = 0; idx < arr_size; idx++)
    {
        printf ("%d ", *(arr + idx));
    }
    
    
    return 0;
}

void quick_sort (uint32_t *arr, int size, int (*find_pivot)(uint32_t *arr, int start, int end, int shift))
{
    assert (arr && size);
    
    quick_sort_ (arr, 0, size - 1, find_pivot);
}

void quick_sort_ (uint32_t *arr, int start, int end, int (*find_pivot)(uint32_t *arr, int start, int end, int shift))
{
    if (start >= end)
    {
        return;
    }
    int pivot = find_pivot (arr, start, end, 1);
    int changed_pivot = hoar_partition (arr, pivot, start, end);

    quick_sort_ (arr, start, changed_pivot, find_pivot);
    quick_sort_ (arr, changed_pivot + 1, end, find_pivot);
}

int hoar_partition (uint32_t *arr, int pivot, int start, int end)
{
    assert (arr);

    int left = start; 
    int right = end;
    uint32_t pivot_val = arr[pivot];

    while (left <= right)
    {
        while (arr[left] < pivot_val)
        {
            left++;
        }
        while (arr[right] > pivot_val)
        {
            right--;
        }
        
        if (left >= right)
        {
            return right;
        }

        swap_uint32 (arr + left++, arr + right--);
    }

    return right;
}

int median_of_medians (uint32_t *arr, int start, int end, int shift)
{
    assert (arr);
    
    for (int block_idx = start + shift/2; block_idx <= end; block_idx += shift*5)
    {
        if (block_idx + shift*5 - 1 >= end)
        {
            bubble_sort (arr, block_idx, end, shift);       
        }
        else
        {
            bubble_sort (arr, block_idx, block_idx + shift*5 - 1, shift);       
        }
    }

    if ((end - start) / (5*shift) < 2)
    {
        return (end - shift - start + 1)/2 + start + shift/2;
    }

    return median_of_medians (arr, start, end, shift*5);
}

void swap_uint32 (uint32_t *val1, uint32_t *val2)
{
    assert (val1 && val2);

    uint32_t temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void bubble_sort (uint32_t *arr, int start, int end, int shift)
{
    assert (arr && shift);

    for (int k = 0; k <= end - start + 1; k += shift)
    {
        for (int j = start + shift; j <= end - k; j += shift)
        {
            if (arr[j] < arr[j - shift])
            {
                swap_uint32 (arr + j, arr + j - shift);
            }
        }
    }
}
 
int median_of_three (uint32_t *arr, int start, int end, int shift)
{
    assert (arr);
    
    int mid = start + (end - start)/2;
    
    if (mid == start || mid == end)
    {
        return mid;
    }

    if (arr[mid] > arr[end])
    {
        swap_uint32 (arr + mid, arr + end);
    }
    if (arr[start] > arr[mid])
    {
        swap_uint32 (arr + mid, arr + start);
        
        if (arr[mid] > arr[end])
        {
            swap_uint32 (arr + mid, arr + end);
        }
    }

    return mid;
}

int central (uint32_t *arr, int start, int end, int shift)
{
    assert (arr);

    return start + (end - start)/2;
}

int rand_pivot (uint32_t *arr, int start, int end, int shift)
{
    assert (arr);

    srand (time(NULL));

    int pivot = (rand () % (end - start)) + start;
    
    return pivot;
}