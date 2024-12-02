#include <stdio.h>
#define MAX 100


void DFS(int A[MAX][MAX], int start, int N) 
{
    int visited[MAX] = {0}; 
    int stack[MAX], top = -1; 
    
    stack[++top] = start;
    visited[start] = 1;
    

    while (top != -1) 
	{
    
        int V = stack[top--];
        
    
        printf("Visited: %d\n", V);
        
        for (int J = 0; J < N; J++) {
            if (V != J && A[V][J] != 0 && visited[J] == 0) {
                stack[++top] = J; 
                visited[J] = 1;   
            }
        }
    }
}

int main()
 {
    int N = 5;
    int A[MAX][MAX] = { 
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };
    
    int start = 0; // Starting node
    printf("Depth First Search starting from node %d:\n", start);
    DFS(A, start, N);
    
    return 0;
}

