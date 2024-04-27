/*
 * C Program to Implement Postman Sort Algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

// Declaration of the function to arrange sequence with the same base
void arrange(int,int);

// Declaration of global variables
int array[10000], array1[10000];
int i, j, temp, max, count=10000, maxdigits = 0, c = 0;
double start, end;

// Declaration of function to generate random numbers
int generateRandom();

// Main function of the program
void main()
{
    // Start the timer
    start = omp_get_wtime();

    int t1, t2, k, t, n = 1;

    // Generating random numbers instead of prompting user input
    srand(time(NULL));
    for(int i = 0; i < 10000; i++){
        array1[i]= generateRandom();
        array[i]= array1[i];
    }

    // Determine the maximum number of digits in the elements of the array
    for (i = 0; i < count; i++)
    {
        t = array[i];
        while(t > 0)
        {
            c++;
            t = t / 10;
        }
        if (maxdigits < c)
            maxdigits = c;
        c = 0;
    }
    while(--maxdigits)
        n = n * 10;

    // Sort the array based on the most significant digit
    for (i = 0; i < count; i++)
    {
        max = array[i] / n;
        t = i;
        for (j = i + 1; j < count;j++)
        {
            if (max > (array[j] / n))
            {
                max = array[j] / n;
                t = j;
            }
        }
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
/* Function to arrange the sequence with the same base */
void arrange(int k,int n)
{
    for (i = k; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (array1[i] > array1[j])
            {
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
