/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#ifndef _GRAPH_H_
#define _GRAPH_H_

// Structures
typedef struct VERTEX {
    int id;
    int value;
    int out_degree;
    int* adjacents;
} VERTEX;

typedef struct edge {
    int start;
    int end;
    int weight;
} Edge;

typedef struct graph {
    int n_vertices;
    int n_edges;
    VERTEX** vertices;
    Edge** edges;
    char** matrix;
    int directed;
    char representation;
} Graph;

// Initializers
void init_graph(Graph** g);
void initVERTEX(VERTEX** v);
void initEdge(Edge** e);
void initMatrix(Graph** g, int size);

// Add VERTEX/Edge
void addVERTEX(Graph** g, int value);
void add_edge(Graph** g, int start, int end, int weight);
void add_edge_List(Graph** g, int start, int end, int weight);
void add_edge_Matrix(Graph** g, int start, int end, int weight);

// Removal
void remove_edge(Graph** g, int start, int end);
void remove_edge_List(Graph** g, int start, int end);
void remove_edge_Matrix(Graph** g, int start, int end);

// Edges
void sortEdges(Graph** g);
void transpose_List(Graph **g);
void transpose_Matrix(Graph **g);
void transpose(Graph** g);

// Print
void print_graph(Graph* g);
void print_graph_List(Graph* g);
void print_graph_Matrix(Graph* g);

void printAdjacents(Graph* g, int VERTEX);
void printAdjacencyMatrix(Graph* g, int VERTEX);
void printAdjacencyList(Graph* g, int VERTEX);

void findSmallestEdge(Graph* g);

#endif
