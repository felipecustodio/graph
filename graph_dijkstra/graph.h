/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "stack.h"

#define TRUE  1
#define FALSE 0

// Structures
typedef struct vertex {
    int id;
    // 0 - undiscovered
    // 1 - discovered
    int discovered;
    int parent;
} VERTEX;

typedef struct graph {
    int n_vertices;
    VERTEX** vertices;
    char** matrix;
} GRAPH;

// Initializers
void init_graph(GRAPH** g, int vertices);

// Add new edge
void add_edge(GRAPH* g, int start, int end, int weight);

// Removal
void remove_edge(GRAPH** g, int start, int end);

// Print
void print_graph(GRAPH* g);

#endif
