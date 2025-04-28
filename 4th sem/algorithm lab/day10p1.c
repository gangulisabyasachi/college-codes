/*#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph (s, u, v, t)

// Function to perform a BFS and find the augmenting path
bool bfs(int graph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    for (int i = 0; i < V; i++) visited[i] = false;
    
    visited[s] = true;
    parent[s] = -1;

    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = s;

    while (front < rear) {
        int u = queue[front++];
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] > 0) {  // If the vertex is not visited and there is a residual capacity
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                queue[rear++] = v;
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    return false;
}

// Function to implement the Ford-Fulkerson algorithm using BFS
int fordFulkerson(int graph[V][V], int s, int t) {
    int parent[V];
    int maxFlow = 0;

    // Residual graph
    int residualGraph[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            residualGraph[i][j] = graph[i][j];
        }
    }

    // Augment the flow while there is an augmenting path
    while (bfs(residualGraph, s, t, parent)) {
        // Find the maximum flow through the path found by BFS
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = (pathFlow < residualGraph[u][v]) ? pathFlow : residualGraph[u][v];
        }

        // Update residual capacities of the edges and reverse edges along the path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    // Flow network represented as an adjacency matrix
    int graph[V][V] = {
        {0, 20, 10, 0},
        {0, 0, 30, 10},
        {0, 0, 0, 20},
        {0, 0, 0, 0}
    };

    int source = 0; // 's'
    int sink = 3;   // 't'

    printf("The maximum possible flow is %d\n", fordFulkerson(graph, source, sink));

    return 0;
}
*/


#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 10 // Maximum number of vertices in the graph (can be adjusted as needed)

// Function to perform a BFS and find the augmenting path
bool bfs(int graph[MAX_VERTICES][MAX_VERTICES], int s, int t, int parent[], int V) {
    bool visited[MAX_VERTICES];
    for (int i = 0; i < V; i++) visited[i] = false;
    
    visited[s] = true;
    parent[s] = -1;

    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    queue[rear++] = s;

    while (front < rear) {
        int u = queue[front++];
        
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] > 0) {  // If the vertex is not visited and there is a residual capacity
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                queue[rear++] = v;
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    return false;
}

// Function to implement the Ford-Fulkerson algorithm using BFS
int fordFulkerson(int graph[MAX_VERTICES][MAX_VERTICES], int s, int t, int V) {
    int parent[MAX_VERTICES];
    int maxFlow = 0;

    // Residual graph
    int residualGraph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            residualGraph[i][j] = graph[i][j];
        }
    }

    // Augment the flow while there is an augmenting path
    while (bfs(residualGraph, s, t, parent, V)) {
        // Find the maximum flow through the path found by BFS
        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = (pathFlow < residualGraph[u][v]) ? pathFlow : residualGraph[u][v];
        }

        // Update residual capacities of the edges and reverse edges along the path
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int V, source, sink;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Input the adjacency matrix (capacity graph)
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (capacity graph) of the flow network:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Capacity of edge from vertex %d to vertex %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the source and sink vertices
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("Enter the sink vertex: ");
    scanf("%d", &sink);

    // Run the Ford-Fulkerson algorithm and output the maximum flow
    printf("The maximum possible flow is %d\n", fordFulkerson(graph, source, sink, V));

    return 0;
}
