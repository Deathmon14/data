#include <stdio.h>
#include <stdlib.h>
#define INF 999
#define MAX 10
void floydWarshall(int n, int graph[MAX][MAX], int dist[MAX][MAX]) {
 int i, j, k;
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 dist[i][j] = graph[i][j];
 }
 }
 // Floyd-Warshall algorithm
 for (k = 0; k < n; k++) {
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 if (dist[i][k] + dist[k][j] < dist[i][j]) {
 dist[i][j] = dist[i][k] + dist[k][j];
 }
 }
 }
 }
}
int main() {
 int n, i, j;
 int graph[MAX][MAX], dist[MAX][MAX];
 printf("Enter the number of vertices: ");
 scanf("%d", &n);
 printf("Enter the cost adjacency matrix (use %d for INF):\n", INF);
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 scanf("%d", &graph[i][j]);
 if (graph[i][j] == 0 && i != j) {
 graph[i][j] = INF; // No edge between i and j
 }
 }
 }
 floydWarshall(n, graph, dist);
 printf("\nThe shortest paths between all pairs of vertices:\n");
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 if (dist[i][j] == INF) {
 printf("INF\t");
 } else {
 printf("%d\t", dist[i][j]);
 }
 }
 printf("\n");
 }
 return 0;
}
