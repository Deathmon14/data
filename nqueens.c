#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k) {
    int i;
    for(i = 1; i < k; i++) // Check whether two queens attack vertically or horizontally
        if(x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))
            return 0; // Queen cannot be placed in the k-th column
    return 1; // k-th queen can be successfully placed
}

void display(int x[], int n) {
    char board[20][20];
    int i, j;
    for(i = 1; i <= n; i++) // No queen has been placed initially
        for(j = 1; j <= n; j++)
            board[i][j] = 'x';
    for(i = 1; i <= n; i++) // Place the queens on the chess board
        board[i][x[i]] = 'Q';
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

void nqueens(int n) {
    int x[30];
    int k = 1;
    x[k] = 0; // Initialize row
    while(k != 0) {
        x[k] = x[k] + 1; // Go to next column
        while((x[k] <= n) && !place(x, k))
            x[k] = x[k] + 1;
        if(x[k] <= n) { // Place the queen
            if(k == n)
                display(x, n);
            else {
                k++; // Try for next queen
                x[k] = 0;
            }
        } else
            k--; // Backtrack, queen can't be placed
    }
}

int main() {
    int n;
    printf("Enter number of queens n>3: ");
    scanf("%d", &n);
    printf("The solution to the queen problem is:\n");
    nqueens(n);
    return 0;
}
