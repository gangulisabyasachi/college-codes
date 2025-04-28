#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Number of vertices
#define V 5

// Priority Queue structure
typedef struct {
    int vertex;
    int distance;
} Node;

// Priority Queue operations
typedef struct {
    Node* heap;
    int size;
} PriorityQueue;

// Priority Queue functions
PriorityQueue* createQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->heap = (Node*)malloc(V * sizeof(Node));
    pq->size = 0;
    return pq;
}

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < pq->size && pq->heap[left].distance < pq->heap[smallest].distance) {
        smallest = left;
    }
    
    if (right < pq->size && pq->heap[right].distance < pq->heap[smallest].distance) {
        smallest = right;
    }
    
    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

Node extractMin(PriorityQueue* pq) {
    if (pq->size == 0) {
        Node temp = {-1, INT_MAX};
        return temp;
    }
    Node root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapify(pq, 0);
    return root;
}

void insert(PriorityQueue* pq, int vertex, int distance) {
    pq->heap[pq->size].vertex = vertex;
    pq->heap[pq->size].distance = distance;
    int i = pq->size++;
    
    while (i > 0 && pq->heap[(i - 1) / 2].distance > pq->heap[i].distance) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Dijkstra's Algorithm implementation using priority queue
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int prev[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[src] = 0;

    PriorityQueue* pq = createQueue();
    insert(pq, src, 0);

    while (pq->size > 0) {
        Node u = extractMin(pq);
        int uVertex = u.vertex;

        for (int v = 0; v < V; v++) {
            if (graph[uVertex][v] != INT_MAX) {
                int alt = dist[uVertex] + graph[uVertex][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = uVertex;
                    insert(pq, v, dist[v]);
                }
            }
        }
    }

    printf("Vertex \t Distance from Source \t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%c \t %d \t\t\t", 's' + i, dist[i]);
        int path = i;
        while (prev[path] != -1) {
            printf("%c <- ", 's' + path);
            path = prev[path];
        }
        printf("%c\n", 's' + path);
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[V][V] = {
        {0, 10, INT_MAX, 5, INT_MAX},
        {INT_MAX, 0, 1, 2, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, 4},
        {INT_MAX, 3, 9, 0, 2},
        {7, INT_MAX, 6, INT_MAX, 0}
    };

    int src = 0;  // Source vertex (s)
    printf("Dijkstra's Algorithm (Shortest Path using Priority Queue)\n");
    dijkstra(graph, src);
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 10

// Priority Queue structure
typedef struct {
    int vertex;
    int distance;
} Node;

// Priority Queue operations
typedef struct {
    Node* heap;
    int size;
} PriorityQueue;

// Priority Queue functions
PriorityQueue* createQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->heap = (Node*)malloc(MAX_VERTICES * sizeof(Node));
    pq->size = 0;
    return pq;
}

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < pq->size && pq->heap[left].distance < pq->heap[smallest].distance) {
        smallest = left;
    }
    
    if (right < pq->size && pq->heap[right].distance < pq->heap[smallest].distance) {
        smallest = right;
    }
    
    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

Node extractMin(PriorityQueue* pq) {
    if (pq->size == 0) {
        Node temp = {-1, INT_MAX};
        return temp;
    }
    Node root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    heapify(pq, 0);
    return root;
}

void insert(PriorityQueue* pq, int vertex, int distance) {
    pq->heap[pq->size].vertex = vertex;
    pq->heap[pq->size].distance = distance;
    int i = pq->size++;
    
    while (i > 0 && pq->heap[(i - 1) / 2].distance > pq->heap[i].distance) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Dijkstra's Algorithm implementation using priority queue
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int vertices) {
    int dist[MAX_VERTICES];
    int prev[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[src] = 0;

    PriorityQueue* pq = createQueue();
    insert(pq, src, 0);

    while (pq->size > 0) {
        Node u = extractMin(pq);
        int uVertex = u.vertex;

        for (int v = 0; v < vertices; v++) {
            if (graph[uVertex][v] != INT_MAX) {
                int alt = dist[uVertex] + graph[uVertex][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = uVertex;
                    insert(pq, v, dist[v]);
                }
            }
        }
    }

    printf("Vertex \t Distance from Source \t Path\n");
    for (int i = 0; i < vertices; i++) {
        printf("%c \t %d \t\t\t", 's' + i, dist[i]);
        int path = i;
        while (prev[path] != -1) {
            printf("%c <- ", 's' + path);
            path = prev[path];
        }
        printf("%c\n", 's' + path);
    }
}

int main() {
    int vertices, edges;
    
    // Input number of vertices and edges
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    // Initialize graph with infinity
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Input edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            graph[src][dest] = weight;
        }
    }

    int src;
    printf("Enter the source vertex (0 to %d): ", vertices - 1);
    scanf("%d", &src);

    printf("Running Dijkstra's Algorithm...\n");
    dijkstra(graph, src, vertices);
    
    return 0;
}

*/
