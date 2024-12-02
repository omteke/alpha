#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

#define INFINITY 99999

int main() {
    int i, j, k, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int W[n][n], Q[n][n];

    printf("Enter the weight matrix (use 0 for no connection):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(W[i][j] != 0) {
                Q[i][j] = W[i][j];
            } else {
                Q[i][j] = INFINITY;
            }
        }
    }

    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(i != j) {
                    Q[i][j] = fmin(Q[i][j], (Q[i][k] + Q[k][j]));
                }
            }
        }
    }

    printf("The shortest path matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(Q[i][j] == INFINITY) {
                printf("INF ");
            } else {
                printf("%d ", Q[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}

