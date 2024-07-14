#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to perform BFS
void bfs(int n, int a[n][n], int source, int s[]) {
    int q[100], f = 0, r = 0, u, v;
    q[r] = source;
    for (int i = 0; i < n; i++) {
        s[i] = 0;
    }
    s[source] = 1;
    while (f <= r) {
        u = q[f++];
        for (v = 0; v < n; v++) {
            if (a[u][v] && !s[v]) {
                q[++r] = v;
                s[v] = 1;
            }
        }
    }
}

// Function to generate a random adjacency matrix
void generateRandomGraph(int n, int a[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                a[i][j] = rand() % 2;
            } else {
                a[i][j] = 0;
            }
        }
    }
}

int main() {
    int s[100];
    printf("n\tTime taken (seconds)\n");
    
    for (int n = 10; n <= 1000; n += 10) {
        int a[100][100];
        generateRandomGraph(n, a);
        int source = 0;

        clock_t start = clock();
        bfs(n, a, source, s);
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%f\n", n, time_taken);
    }

    return 0;
}