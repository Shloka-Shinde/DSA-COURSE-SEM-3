// Define a structure for a node in the adjacency list
typedef struct node {
    int vertex;
    struct node* next;
}node;

// Define the structure for the graph
typedef struct graph {
    int numVertices;
    node** adjLists;       // Array of adjacency lists
}graph;

void init_graph(graph *g,int v);
void addEdge(graph *g,int s,int d);
node * create_node(int d);
void display_list(graph *g);
void BFS(graph g,int sVertex);
void DFS(graph g,int sVertex);

#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "queue.h"
#include "stack.h"

// Function to initialize a graph with a specified number of vertices
void init_graph(graph *g,int v){
	g->numVertices = v;
	g->adjLists = (node**)malloc(v * sizeof(node*));
	for (int i = 0; i < v; i++) {
        	g->adjLists[i] = NULL;
    }
    return;
}

// Function to create a new node
node * create_node(int d){
	node* nn = (node*)malloc(sizeof(node));
    	nn->vertex = d;
    	nn->next = NULL;
    	return nn;
}
// Function to add an undirected edge to the graph
void add_edge(graph *g,int s,int d){
    // Add edge from src to dest
    node* nn = create_node(d);
    nn->next = g->adjLists[s];
    g->adjLists[s] = nn;

    // Add edge from dest to src (since the graph is undirected)
    nn = create_node(s);
    nn->next = g->adjLists[d];
    g->adjLists[d] = nn;
}


void display_list(graph *g){
	for(int i=0; i < g->numVertices; i++){
        printf("Adjacency list for vertex %d :", i);
        node *p = g->adjLists[i];
        while(p){
            printf("%d ", p->vertex);
            p=p->next;
        }
        printf("\n");
    }
}


void BFS(graph g, int sVertex){
	int k,i;
    queue q;
    init(&q, g.numVertices);
    int *visited=(int *)calloc(g.numVertices,sizeof(int));
    visited[sVertex]=1;
    enqueue(&q, sVertex);
    printf("%d ", sVertex);
    while(!isempty(q)){
        k=dequeue(&q);
        node *p = g.adjLists[k];
        while(p){
            i=p->vertex;
            if(visited[i]==0){
                printf("%d ", i);
                enqueue(&q, i);
                visited[i]=1;
            }
            p=p->next;
        }
    }
}

void DFS(graph g,int sVertex){
	stack s;
    int k, i;
    init_stack(&s, g.numVertices);
    int *visited=(int *)calloc(g.numVertices, sizeof(int));
    visited[sVertex]=1;
    push(&s, sVertex);
    printf("%d ", sVertex);
    while(!isempty_s(s)){
        k=pop(&s);
        if(visited[k]==0){
            visited[k]=1;
            printf("%d ", k);
        }
        node *p = g.adjLists[k];
        while(p){
            i=p->vertex;
            if(visited[i]==0){
                push(&s, i);
            }
            p=p->next;
        }
    }
}