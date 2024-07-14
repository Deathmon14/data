#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key,
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, i;
    
    printf("Enter the number of phone numbers: ");
    scanf("%d", &n);
    
    int *phoneNumbers = (int*)malloc(n * sizeof(int));
    
    // Generate random phone numbers
    srand(time(0));
    for (i = 0; i < n; i++) {
        phoneNumbers[i] = rand() % 1000000000 + 100000000; // Generate 9-digit numbers
    }
    
    clock_t start = clock();
    insertionSort(phoneNumbers, n);
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted phone numbers:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", phoneNumbers[i]);
    }
     printf("Time taken to sort: %f seconds.\n", time_taken);
    free(phoneNumbers);
    return 0;
}