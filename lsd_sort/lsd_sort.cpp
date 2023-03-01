#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

#include "lsd_sort.h"

void swap_uint32 (uint32_t *val1, uint32_t *val2)
{
    uint32_t temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void lsd_sort (uint32_t *arr, int size)
{
    uint32_t digit = 1;
    uint32_t *arr2 = (uint32_t *)calloc (size, sizeof (uint32_t));

    for (int rank = 10; rank > 0; rank--)
    {
        int count[10] = {0};
        
        for (int i = 0; i < size; i++)
        {
            count[(arr[i]/digit)%10]++;
        } 
        for (int i = 9; i >= 0; i--)
        {
            if (count[i])
            {
                count[i] = 0;
                for (int j = i - 1; j >= 0; j--)
                {
                    count[i] += count[j]; 
                }
            }
        }
        for (int i = 0; i < size; i++)
        {   
            int c = (arr[i]/digit)%10;
            arr2[count[c]] = arr[i];
            (count[c])++;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = arr2[i];
        }
        digit *= 10;
    }

    free (arr2);
}