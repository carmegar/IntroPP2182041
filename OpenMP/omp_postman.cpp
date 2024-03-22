/*

  Purpose:

    Implement the sorting algorithm known as Postman Sort efficiently using parallelism 
    through OpenMP. This algorithm sorts a large set of numbers based on their most significant 
    digits, dividing the work among multiple threads to enhance performance on multi-core systems.

  Example:

    21 march 2024 10:45:54 PM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Author:
  George 
  OpenMP Modification:
  21 march 2024, Universidad Industrial de Santander carlos2182041@correouis.edu.co                   
  This OpenMP Modification makes a parallelization of the original Code...  
*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h> 

#define CHUNKSIZE 10000

void arrange(int,int);
int array[10000], array1[10000];
int i, j, temp, max, count=10000, maxdigits = 0, c = 0, chunk=CHUNKSIZE;
double start, end; 

int generateRandom();

void main()
{
    start = omp_get_wtime(); 
    int t1, t2, k, t, n = 1;

    // Generate random numbers for the array
    srand(time(NULL));
    #pragma omp for schedule(dynamic, chunk) 
    for(int i = 0; i < 10000
; i++){
        array1[i]= generateRandom();
        array[i]= array1[i];
    }

    // Determine the number of digits of each number in the array
    #pragma omp for schedule(dynamic, chunk) 
    for (i = 0; i < count; i++)
    {
        t = array[i];        
        while(t > 0)
        {
            c++;
            t = t / 10;        
        }
        if (maxdigits < c) 
            maxdigits = c;   // Update maximum digits
        c = 0;
    }
    while(--maxdigits) 
        n = n * 10;      

    // Sort the array based on the most significant digit
    for (i = 0; i < count; i++)
    {
        max = array[i] / n;        
        t = i;
        #pragma omp for schedule(dynamic, chunk)
        for (j = i + 1; j < count;j++)    
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n;   // Find greatest MSB
                t = j;
            }
        }
        // Swap elements in array1 and array
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }
    
    // Continue sorting elements with the same base
    while (n >= 1)
    {
        for (i = 0; i < count;)
        {
            t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++);
                arrange(i, j);
            i = j;
        }
        n = n / 10;
    }

    // Stop the timer and display the elapsed time
    end = omp_get_wtime();
    printf("This execution took %f seconds\n", end - start);
}

/* Function to arrange sequences with the same base */
void arrange(int k,int n)
{
    for (i = k; i < n - 1; i++)
    {
        // Sort buckets of array elements
        #pragma omp for schedule (dynamic, chunk)
        for (j = i + 1; j < n; j++)
        {
            if (array1[i] > array1[j])
            {
                // Swap elements in array1 and array
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = (array[i] % 10);
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}

// Function to generate a random number
int generateRandom()
{
    int number = rand()%10000;
    return number; 
}
