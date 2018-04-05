/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#ifndef _GRAPH_H_
#define _GRAPH_H_

// Structures
typedef struct vertex {
    int id;
    int discovered;
} Vertex;

typedef struct graph {
    int n_vertices;
    Vertex** vertices;
    char** matrix;
} Graph;

// Initializers
void initGraph(Graph** g, int vertices);

// Add new edge
void addEdge(Graph* g, int start, int end);

// Removal
void removeEdge(Graph** g, int start, int end);

// Print
void printGraph(Graph* g);

#endif
