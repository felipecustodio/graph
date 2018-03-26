/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#ifndef _GRAPH_H_
#define _GRAPH_H_

// Structures
typedef struct vertex {
    int id;
    int value;
    int out_degree;
    int* adjacents;
} Vertex;

typedef struct edge {
    int start;
    int end;
    int weight;
} Edge;

typedef struct graph {
    int n_vertices;
    int n_edges;
    Vertex** vertices;
    Edge** edges;
    char** matrix;
    int directed;
    char representation;
} Graph;

// Initializers
void initGraph(Graph** g);
void initVertex(Vertex** v);
void initEdge(Edge** e);
void initMatrix(Graph** g, int size);

// Add Vertex/Edge
void addVertex(Graph** g, int value);
void addEdge(Graph** g, int start, int end, int weight);
void addEdge_List(Graph** g, int start, int end, int weight);
void addEdge_Matrix(Graph** g, int start, int end, int weight);

// Removal
void removeEdge(Graph** g, int start, int end);
void removeEdge_List(Graph** g, int start, int end);
void removeEdge_Matrix(Graph** g, int start, int end);

// Edges
void sortEdges(Graph** g);
void transpose_List(Graph **g);
void transpose_Matrix(Graph **g);
void transpose(Graph** g);

// Print
void printGraph(Graph* g);
void printGraph_List(Graph* g);
void printGraph_Matrix(Graph* g);

void printAdjacents(Graph* g, int vertex);
void printAdjacencyMatrix(Graph* g, int vertex);
void printAdjacencyList(Graph* g, int vertex);

void findSmallestEdge(Graph* g);

#endif
