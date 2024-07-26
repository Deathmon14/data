#include <stdio.h>
#include <limits.h>  // For INT_MAX

#define INF 9999
#define MAX 10

void dij(int n, int v, int cost[MAX][MAX], int dist[]) {
    int i, u, count, w, flag[MAX], min;

    for (i = 0; i < n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }

    flag[v] = 1; // Mark the source vertex as visited
    count = 1;

    while (count < n) {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++) {
            if (!flag[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // No more reachable vertices

        flag[u] = 1;
        count++;

        for (w = 0; w < n; w++) {
            if (!flag[w] && dist[u] + cost[u][w] < dist[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int n, v, i, j;
    int cost[MAX][MAX], dist[MAX];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("The maximum number of nodes supported is %d.\n", MAX);
        return -1;
    }

    printf("\nEnter the cost matrix (0 for no edge, %d for infinity):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }

    printf("\nEnter the source node (0 to %d): ", n-1);
    scanf("%d", &v);

    dij(n, v, cost, dist);

    printf("\nShortest paths from node %d:\n", v);
    for (i = 0; i < n; i++) {
        if (i != v) {
            if (dist[i] == INF)
                printf("%d -> %d: No path\n", v, i);
            else
                printf("%d -> %d: Cost = %d\n", v, i, dist[i]);
        }
    }

    return 0;
}
