#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid; // Return index if found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Return -1 if not found
}

int main() {
    int n, target, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    
    printf("Enter the elements in ascending order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the product ID to search for: ");
    scanf("%d", &target);
    
    clock_t start = clock();
    int index = binarySearch(arr, n, target);
    clock_t end = clock();
    
    if (index != -1)
        printf("Product is available at index %d.\n", index);
    else
        printf("Product is not available.\n");
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to search: %f seconds.\n", time_taken);
    
    free(arr);
    return 0;
}

