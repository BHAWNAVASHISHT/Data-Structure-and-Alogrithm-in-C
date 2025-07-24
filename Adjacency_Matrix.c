#include <stdio.h>
#include <stdlib.h>

int main() {
    int vertices, edges;
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int **adjMatrix = (int **)malloc(vertices * sizeof(int *));
    for (i = 0; i < vertices; i++) {
        adjMatrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge as a pair of vertices (u v):\n");
    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
