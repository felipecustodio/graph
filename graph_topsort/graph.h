/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "stack.h"

// Structures
typedef struct vertex {
    int id;
    // 0 - WHITE - undiscovered
    // 1 - GRAY - discovered but not finished
    // 2 - BLACK - discovered and finished
    int color;
    int parent;
} Vertex;

typedef struct graph {
    int n_vertices;
    Vertex** vertices;
    char** matrix;
} GRAPH;

// Initializers
void initGRAPH(GRAPH** g, int vertices);

// Add new edge
void addEdge(GRAPH* g, int start, int end);

// Removal
void removeEdge(GRAPH** g, int start, int end);

// Traversal
void dfs_visit(GRAPH* g, STACK* s, int node);
void dfs(GRAPH* g, STACK* s);

// Sorting
void topsort(GRAPH* g, STACK* s);

// Print
void printGRAPH(GRAPH* g);

#endif
