#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *, int, int);
void binarySearch(int *, int, int, int);

int main() {
    const int n = 100000;
    int key, i;
    int *list = (int *)malloc(n * sizeof(int));
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        list[i] = rand() % 1000; // Genera números aleatorios entre 0 y 999
    }

    start = clock();
    quickSort(list, 0, n - 1); // Utiliza Quick Sort
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort the list: %lf seconds\n", cpu_time_used);

    printf("Enter the value to search for: ");
    scanf("%d", &key);

    start = clock();
    binarySearch(list, 0, n - 1, key);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to search in the sorted list: %lf seconds\n", cpu_time_used);

    free(list);
    return 0;
}

void quickSort(int *list, int lo, int hi) {
    if (lo < hi) {
        int pivot = list[hi];
        int i = lo - 1;
        for (int j = lo; j <= hi - 1; j++) {
            if (list[j] < pivot) {
                i++;
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        int temp = list[i + 1];
        list[i + 1] = list[hi];
        list[hi] = temp;

        int pi = i + 1;

        quickSort(list, lo, pi - 1);
        quickSort(list, pi + 1, hi);
    }
}

void binarySearch(int *list, int lo, int hi, int key) {
    int mid;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (list[mid] == key) {
            printf("Element found\n");
            return;
        } else if (list[mid] < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("Element not found\n");
}
