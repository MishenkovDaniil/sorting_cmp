#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "slow_sort.h"

void print_arr (uint32_t *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        fprintf (stderr, "[%d]\n", arr[i]);
    }
}

int main ()
{
    const int SIZE = 10;

    uint32_t arr[SIZE] = {};
    
    srand (time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % UINT32_MAX;
    }

    print_arr (arr, SIZE);
    bubble_sort (arr, SIZE);
    fprintf (stderr, "\n\n\n\n\n");
    print_arr (arr, SIZE);
    
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % UINT32_MAX;
    }
    print_arr (arr, SIZE);
    insert_sort (arr, SIZE);
    fprintf (stderr, "\n\n\n\n\n");
    print_arr (arr, SIZE);
    
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % UINT32_MAX;
    }
    print_arr (arr, SIZE);
    select_sort (arr, SIZE);
    print_arr (arr, SIZE);
}

void swap_int32 (uint32_t *val1, uint32_t *val2)
{
    assert (val1 && val2);

    uint32_t temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void bubble_sort (uint32_t *arr, int size)
{
    assert (arr);
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j-1] > arr[j])
            {
                swap_int32 (arr + j - 1, arr + j);
            }
        }
    }
}

void insert_sort (uint32_t *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int k = i;

        while (j >= 0 && arr[k] < arr[j])
        {
            swap_int32 (arr + j, arr + k);
            k--;
            j--;
        }
    }
}

void select_sort (uint32_t *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_num = i;

        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[min_num])
            {
                min_num = j;
            }
        }
        swap_int32 (arr + i, arr + min_num);
    }
}
