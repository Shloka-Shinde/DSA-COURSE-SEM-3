typedef struct Graph {
    int numVertices;
    int **adjMatrix;
} Graph;

void initGraph(Graph* graph, int vertices);
void addEdge(Graph* graph, int src, int dest);
void removeEdge(Graph* graph, int src, int dest);
void displayGraph(Graph* graph);
void freeGraph(Graph* graph);

// Function to initialize the graph with the specified number of vertices
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;  // Initialize with no edges
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // For undirected graph
}

// Function to remove an edge from the graph
void removeEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 0;
    graph->adjMatrix[dest][src] = 0;  // For undirected graph
}

// Function to print the adjacency matrix of the graph
void displayGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to free memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
}

void add_edge_undirected(graph *g, int src, int dest, int wt){

    g->matrix[src - 1][dest - 1] = wt;
    g->matrix[dest - 1][src - 1] = wt;
    return;
}

// Function to find and display all adjacent vertices of a given vertex
void findAdjacentVertices(Graph* graph, int vertex) {
    if (vertex < 0 || vertex >= graph->numVertices) {
        printf("Invalid vertex number.\n");
        return;
    }

    printf("Adjacent vertices of vertex %d:\n", vertex);
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] != 0) {  // Non-zero indicates an edge
            printf("%d ", i);
        }
    }
    printf("\n");
}


