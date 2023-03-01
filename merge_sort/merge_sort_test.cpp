#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

#include "merge_sort.h"
void merge_sort_test ();

int main ()
{
    merge_sort_test();
    return 0;
}

void merge_sort_test ()
{
    FILE *merge_srt_file = fopen ("merge_sort.txt", "w");

    fprintf (merge_srt_file, "[");

    int size = 1000;

    for (int size = 1000; size < 10000000; size += 100000)
    {
        uint32_t *merge_arr  = (uint32_t *)calloc (size, sizeof (uint32_t));
        
        double merge_sort_time = 0;

        for (int i = 0; i < 5; i++)
        {
            srand (time(NULL));
            
            clock_t t0 = 0;

            clock_t merge_time = 0;

            for (int i = 0; i < size; i++)
            {
                merge_arr[i] = rand() % UINT32_MAX;
            }

            t0 = clock();
            merge_sort (merge_arr, size);
            merge_time = clock();
            merge_sort_time += (double)(1000*(merge_time - t0))/CLOCKS_PER_SEC;
        }        

        merge_sort_time /= 5;

        printf ("size = %d\n", size);
        printf ("central time = %lf\n", merge_sort_time);
    
        fprintf (merge_srt_file, "%d,", (int)merge_sort_time);

        fflush (merge_srt_file);
    }

    fprintf (merge_srt_file, "]\n");

    fclose (merge_srt_file);   
}