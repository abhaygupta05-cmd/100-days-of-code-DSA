#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; 
        }
    }

    recStack[node] = 0; 
    return false;
}

void detectCycle(int V, int edges[][2], int E) {
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < E; i++) {
        adjSize[edges[i][0]]++;
    }

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
    }

    int* visited = (int*)calloc(V, sizeof(int));
    int* recStack = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES\n");
                return;
            }
        }
    }

    printf("NO\n");
}