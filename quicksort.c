
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Student {
    int USN;
    char name[10];
    int PhoneNumber;
};
int partition(int a[], int low, int high) {
    int i, j, key, temp;
    key = a[low];
    i = low + 1;
    j = high;
    while (1) {
        while (i < high && key >= a[i])
            i++;
        while (key < a[j])
            j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}
void quicksort(int a[], int low, int high) {
    int j;
    if (low < high) {
        j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}
int main() {
    int i, n;
    clock_t st, end;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    struct Student students[n];
    int usnArray[n];

    for (i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("USN: ");
        scanf("%d", &students[i].USN);
        usnArray[i] = students[i].USN;

        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Phone Number: ");
        scanf("%d", &students[i].PhoneNumber);
    }
    st = clock();
    quicksort(usnArray, 0, n - 1);
    end = clock();
    printf("\nThe sorted USNs are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", usnArray[i]);
    }
    double time_taken = ((double)(end - st)) / CLOCKS_PER_SEC;
    printf("\nTime taken = %f seconds\n", time_taken);
    return 0;
}