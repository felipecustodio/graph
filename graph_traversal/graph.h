/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#ifndef _GRAPH_H_
#define _GRAPH_H_

// Structures
typedef struct VERTEX {
    int id;
    int discovered;
} VERTEX;

typedef struct graph {
    int n_vertices;
    VERTEX** vertices;
    char** matrix;
} Graph;

// Initializers
void init_graph(Graph** g, int vertices);

// Add new edge
void add_edge(Graph* g, int start, int end);

// Removal
void remove_edge(Graph** g, int start, int end);

// Traversal
void bfs(Graph* g, int start, int end);

// Print
void print_graph(Graph* g);

#endif
