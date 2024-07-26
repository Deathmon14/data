#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 999
#define MAX 10

int cost[MAX][MAX], a[MAX][MAX];

int min(int a, int b) {
    return (a < b) ? a : b;
}

void allpaths(int cost[MAX][MAX], int a[MAX][MAX], int n) {
    int i, j, k;
    #pragma omp parallel for num_threads(2)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = cost[i][j];
        }
    }

    #pragma omp parallel for num_threads(3) collapse(2) private(i, j, k)
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][k] != INF && a[k][j] != INF)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
}

int main() {
    int i, j, n;

    printf("\n\nEnter the number of vertices: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("The maximum number of vertices supported is %d.\n", MAX);
        return -1;
    }

    printf("\nEnter the cost adjacency matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    allpaths(cost, a, n);

    printf("The shortest paths obtained are as follows:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
