#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], visited[MAX], n;

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal starting from vertex %d: ", start);
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(start);
    return 0;
}
