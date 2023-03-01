#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

#include "quick_sort.h"
void quick_sort_test ();

int main ()
{
    quick_sort_test();
    return 0;
}

void quick_sort_test ()
{
    FILE *q_srt_m_of_3_file = fopen ("q_srt_m_of_3.txt", "w");
    FILE *q_srt_m_of_ms_file = fopen ("q_srt_m_of_ms.txt", "w");
    FILE *q_srt_random_file = fopen ("q_srt_random.txt", "w");
    FILE *q_srt_central_file = fopen ("q_srt_central.txt", "w");


    fprintf (q_srt_m_of_3_file, "[");
    fprintf (q_srt_m_of_ms_file, "[");
    fprintf (q_srt_random_file, "[");
    fprintf (q_srt_central_file, "[");

    int size = 1000;

    for (int size = 1000; size < 10000000; size += 100000)
    {
        uint32_t *q_srt_m_of_3  = (uint32_t *)calloc (size, sizeof (uint32_t));
        uint32_t *q_srt_m_of_ms = (uint32_t *)calloc (size, sizeof (uint32_t));
        uint32_t *q_srt_random  = (uint32_t *)calloc (size, sizeof (uint32_t));
        uint32_t *q_srt_central = (uint32_t *)calloc (size, sizeof (uint32_t));
        
        double q_srt_m_of_3_time = 0;
        double q_srt_m_of_ms_time = 0;
        double q_srt_random_time = 0;
        double q_srt_central_time = 0;

        for (int i = 0; i < 5; i++)
        {
            srand (time(NULL));
            
            clock_t t0 = 0;

            clock_t m_of_3_time = 0;
            clock_t m_of_ms_time = 0;
            clock_t random_time = 0;
            clock_t central_time = 0;

            for (int i = 0; i < size; i++)
            {
                q_srt_m_of_3[i] = q_srt_m_of_ms[i] = q_srt_random[i] = q_srt_central[i] = rand() % UINT32_MAX;
            }

            t0 = clock();
            quick_sort (q_srt_m_of_3, size, median_of_three);
            m_of_3_time = clock();
            q_srt_m_of_3_time += (double)(1000*(m_of_3_time - t0))/CLOCKS_PER_SEC;
            
            t0 = clock();
            quick_sort (q_srt_m_of_ms, size, median_of_medians);
            m_of_ms_time = clock();
            q_srt_m_of_ms_time += (double)(1000*(m_of_ms_time - t0))/CLOCKS_PER_SEC;

            t0 = clock();
            quick_sort (q_srt_random, size, rand_pivot);
            random_time = clock();
            q_srt_random_time += (double)(1000*(random_time - t0))/CLOCKS_PER_SEC;

            t0 = clock();
            quick_sort (q_srt_central, size, central);
            central_time = clock();
            q_srt_central_time += (double)(1000*(central_time - t0))/CLOCKS_PER_SEC;
        }        

        q_srt_m_of_3_time /= 5;
        q_srt_m_of_ms_time /= 5;
        q_srt_random_time /= 5;
        q_srt_central_time /= 5;
        printf ("size = %d\n", size);
        printf ("m_of_3 time  = %lf\n", q_srt_m_of_3_time);
        printf ("m_of_ms time = %lf\n", q_srt_m_of_ms_time);
        printf ("random time  = %lf\n", q_srt_random_time);
        printf ("central time = %lf\n", q_srt_central_time);
    
        fprintf (q_srt_m_of_3_file,  "%d,", (int)q_srt_m_of_3_time);
        fprintf (q_srt_m_of_ms_file, "%d,", (int)q_srt_m_of_ms_time);
        fprintf (q_srt_random_file,  "%d,", (int)q_srt_random_time);
        fprintf (q_srt_central_file, "%d,", (int)q_srt_central_time);

        fflush (q_srt_m_of_3_file);
        fflush (q_srt_m_of_ms_file);
        fflush (q_srt_random_file);
        fflush (q_srt_central_file);
    }

     fprintf (q_srt_m_of_3_file, "]\n");
    fprintf (q_srt_m_of_ms_file, "]\n");
    fprintf (q_srt_random_file, "]\n");
    fprintf (q_srt_central_file, "]\n");

    fclose (q_srt_m_of_3_file);   
    fclose (q_srt_m_of_ms_file);   
    fclose (q_srt_random_file);   
    fclose (q_srt_central_file);   
}