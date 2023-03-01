#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

#include "lsd_sort.h"

void lsd_sort_test ();

int main ()
{
    lsd_sort_test();
    return 0;
}

void lsd_sort_test ()
{
    FILE *lsd_srt_file = fopen ("lsd_sort.txt", "w");

    fprintf (lsd_srt_file, "[");

    int size = 1000;

    for (int size = 1000; size < 10000000; size += 100000)
    {
        uint32_t *lsd_arr  = (uint32_t *)calloc (size, sizeof (uint32_t));
        
        double lsd_sort_time = 0;

        for (int i = 0; i < 5; i++)
        {
            srand (time(NULL));
            
            clock_t t0 = 0;

            clock_t lsd_time = 0;

            for (int i = 0; i < size; i++)
            {
                lsd_arr[i] = rand() % UINT32_MAX;
            }

            t0 = clock();
            lsd_sort (lsd_arr, size);
            lsd_time = clock();
            lsd_sort_time += (double)(1000*(lsd_time - t0))/CLOCKS_PER_SEC;
        }        

        lsd_sort_time /= 5;

        printf ("size = %d\n", size);
        printf ("lsd sort time = %lf\n", lsd_sort_time);
    
        fprintf (lsd_srt_file, "%d,", (int)lsd_sort_time);

        fflush (lsd_srt_file);

        free (lsd_arr);
    }

    fprintf (lsd_srt_file, "]\n");

    fclose (lsd_srt_file);   
}