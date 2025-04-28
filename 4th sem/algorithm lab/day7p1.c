/*#include <stdio.h>
#include <stdlib.h>

// Disjoint Set Data Structure (Union-Find)
typedef struct {
    int *parent;
    int *rank;
    int size;
} DisjointSet;

// Function to create a disjoint set
DisjointSet* createDisjointSet(int n) {
    DisjointSet *ds = (DisjointSet *)malloc(sizeof(DisjointSet));
    ds->size = n;
    ds->parent = (int *)malloc(n * sizeof(int));
    ds->rank = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }

    return ds;
}

// Find function with path compression
int find(DisjointSet *ds, int x) {
    if (ds->parent[x] != x) {
        ds->parent[x] = find(ds, ds->parent[x]);
    }
    return ds->parent[x];
}

// Union function by rank
void unionSets(DisjointSet *ds, int x, int y) {
    int rootX = find(ds, x);
    int rootY = find(ds, y);

    if (rootX != rootY) {
        // Union by rank
        if (ds->rank[rootX] < ds->rank[rootY]) {
            ds->parent[rootX] = rootY;
        } else if (ds->rank[rootX] > ds->rank[rootY]) {
            ds->parent[rootY] = rootX;
        } else {
            ds->parent[rootY] = rootX;
            ds->rank[rootX]++;
        }
    }
}

// Edge structure to represent each edge
typedef struct {
    int u, v, weight;
} Edge;

// Function to compare edges (for sorting)
int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal’s Algorithm to find MST
void kruskal(int n, Edge *edges, int m) {
    DisjointSet *ds = createDisjointSet(n);

    // Sort edges based on their weight
    qsort(edges, m, sizeof(Edge), compareEdges);

    printf("\nMinimum Spanning Tree (MST):\n");
    int mstWeight = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Check if the edge forms a cycle
        if (find(ds, u) != find(ds, v)) {
            unionSets(ds, u, v);
            printf("%d -- %d == %d\n", u, v, weight);
            mstWeight += weight;
        }
    }

    printf("\nTotal weight of MST: %d\n", mstWeight);

    // Free the memory
    free(ds->parent);
    free(ds->rank);
    free(ds);
}

int main() {
    int n, m;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));

    // Input edges (u, v, weight)
    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Apply Kruskal's Algorithm to find the MST
    kruskal(n, edges, m);

    // Free the memory
    free(edges);

    return 0;
}
*/

#include <stdio.h>
#include <limits.h>

#define INF INT_MAX // Represent infinity

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, minIndex;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Dijkstra's algorithm to find the shortest path from source vertex src
void dijkstra(int graph[][9], int V, int src) {
    int dist[V];  // Array to store the shortest distance from the source
    int sptSet[V];  // Shortest path tree set (for visited nodes)

    // Initialize all distances as infinity and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }

    // Distance from source to source is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Choose the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet, V);

        // Mark the chosen vertex as processed
        sptSet[u] = 1;

        // Update dist[] for the adjacent vertices of the chosen vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if there is a shorter path from u to v
            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the distance array
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%c\t\t%d\n", 'a' + i, dist[i]);
    }
}

int main() {
    int V = 9;  // Number of vertices (a, b, c, d, e, f, g, h, i)
    int graph[V][V];

    // Take adjacency matrix as input from user
    printf("Enter the adjacency matrix (use -1 for no edge and other positive integers for weights):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int weight;
            scanf("%d", &weight);
            // If no edge exists, set to INF
            graph[i][j] = (weight == -1) ? INF : weight;
        }
    }

    // Take the source vertex input
    char src_char;
    printf("Enter the source vertex (a, b, c, ...): ");
    scanf(" %c", &src_char);
    int src = src_char - 'a';  // Convert character to index (a -> 0, b -> 1, ..., i -> 8)

    // Run Dijkstra's algorithm
    dijkstra(graph, V, src);

    return 0;
}
