#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

#include "slow_sorts.h"

void slow_sorts_test ();

int main ()
{
    slow_sorts_test();
    return 0;
}

void slow_sorts_test ()
{
    FILE *bubble_sort_file = fopen ("bubble_sort.txt", "w");
    FILE *insert_sort_file = fopen ("insert_sort.txt", "w");
    FILE *select_sort_file = fopen ("select_sort.txt", "w");

    fprintf (bubble_sort_file, "[\n");
    fprintf (insert_sort_file, "[\n");
    fprintf (select_sort_file, "[\n");

    int size = 1000;

    for (int size = 1000; size < 1000000; size += 10000)
    {
        uint32_t *bubble_arr = (uint32_t *)calloc (size, sizeof (uint32_t));
        uint32_t *insert_arr = (uint32_t *)calloc (size, sizeof (uint32_t));
        uint32_t *select_arr = (uint32_t *)calloc (size, sizeof (uint32_t));
        
        double bubble_sort_time = 0;
        double insert_sort_time = 0;
        double select_sort_time = 0;

        for (int i = 0; i < 5; i++)
        {
            srand (time(NULL));
            
            clock_t t0 = 0;

            clock_t bubble_time = 0;
            clock_t insert_time = 0;
            clock_t select_time = 0;

            for (int i = 0; i < size; i++)
            {
                bubble_arr[i] = insert_arr[i] = select_arr[i] = rand() % UINT32_MAX;
            }

            t0 = clock();
            bubble_sort (bubble_arr, size);
            bubble_time = clock();
            bubble_sort_time += (double)(1000*(bubble_time - t0))/CLOCKS_PER_SEC;
            
            t0 = clock();
            insert_sort (insert_arr, size);
            insert_time = clock();
            insert_sort_time += (double)(1000*(insert_time - t0))/CLOCKS_PER_SEC;

            t0 = clock();
            select_sort (select_arr, size);
            select_time = clock();
            select_sort_time += (double)(1000*(select_time - t0))/CLOCKS_PER_SEC;
        }        
        bubble_sort_time /= 5;
        insert_sort_time /= 5;
        select_sort_time /= 5;
        printf ("size = %d\n", size);
        printf ("bubble time = %lf\n", bubble_sort_time);
        printf ("insert time = %lf\n", insert_sort_time);
        printf ("select time = %lf\n", select_sort_time);
    
        fprintf (bubble_sort_file, "%d,", (int)bubble_sort_time);
        fprintf (insert_sort_file, "%d,", (int)insert_sort_time);
        fprintf (select_sort_file, "%d,", (int)select_sort_time);

        fflush (bubble_sort_file);
        fflush (insert_sort_file);
        fflush (select_sort_file);
    }

    fprintf (bubble_sort_file, "]\n");
    fprintf (insert_sort_file, "]\n");
    fprintf (select_sort_file, "]\n");

    fclose (bubble_sort_file);   
    fclose (insert_sort_file);   
    fclose (select_sort_file);   
}