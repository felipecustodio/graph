/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graph.h"
#include "stack.h"

// initializers
void init_graph(GRAPH** g, int vertices) {
    int i, j;
    (*g) = (GRAPH*)malloc(sizeof(GRAPH));
    // initialize vertices
    (*g)->n_vertices = vertices;
    (*g)->vertices = (VERTEX**)malloc(sizeof(VERTEX*) * vertices);
    for (i = 0; i < vertices; i++) {
        (*g)->vertices[i] = (VERTEX*)malloc(sizeof(VERTEX));
        (*g)->vertices[i]-> id = i;
        // discovered 0 - white (undiscovered)
        (*g)->vertices[i]->discovered = 0;
        (*g)->vertices[i]->parent = -1;
    }
    // initialize adjacency matrix
    (*g)->matrix = (char**)malloc(sizeof(char*) * vertices);
    for (i = 0; i < vertices; i++) {
        (*g)->matrix[i] = (char*)malloc(sizeof(char) * vertices);
        for (j = 0; j < vertices; j++) {
            (*g)->matrix[i][j] = -1;
        }
    }
}

// add edge between nodes 'start' and 'end' with weight 'weight'
void add_edge(GRAPH* g, int start, int end, int weight) {
    g->matrix[start][end] = weight;
}


// remove edge between nodes 'start' and 'end'
void remove_edge(GRAPH** g, int start, int end) {
    (*g)->matrix[start][end] = -1;
}

// print graph as adjacency matrix
void print_graph(GRAPH* g) {
    int i, j;
    for (i = 0; i < g->n_vertices; i++) {
        for (j = 0; j < g->n_vertices; j++) {
            if (g->matrix[i][j] > -1) {
                printf("%d ", g->matrix[i][j]);
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

/****************/
/*  PRIM'S MST  */
/****************/
// check if all nodes in a graph were reached
int all_discovered(GRAPH* g) {
    int i;
    int discovered = 0;
    for (i = 0; i < g->n_vertices; i++) {
        ((*g)->vertices[i]->discovered == 0) {
            discovered++;
        }
    }
    if (discovered == n_vertices) {
        return TRUE;
    } else {
        return FALSE;
    }
}

// print predecessors
void print_predecessors(GRAPH* g) {
    int i;
    for (i = 0; i < g->n_vertices; i++) {
        printf("%d ", g->vertices[i]->parent);
    }
}

// find smallest edge going out from v
int find_smallest_edge(GRAPH* g, int v) {
    int adjacent = -1;
    int min = INFINITY;
    for (adjacent = 0; adjacent < g->n_vertices; adjacent++) {
        if (g->matrix[v][adjacent] < min) {
            if (!g->vertices[adjacent]->discovered) {
                min = adjacent;
            }
        }
    }
    return adjacent;
}

// minimum spanning tree with Prim's algorithm
void prim(GRAPH* g) {
    int x, y;
    STACK* reached = stack_init();
    // discover first vertex (0)
    push(reached, 0);
    g->vertices[0]->discovered = 1;
    while(!all_discovered(g)) {
        // find edge between (x,y)
        // with the smallest cost
        x = pop(reached);
        y = find_smallest_edge(g, x);
        // set x as predecessor of y
        g->vertices[y]->parent = x;
        // mark y as reached nodes
        g->vertices[y]->discovered = 1;
        // add y to reached set
        push(reached, y);
    }
    print_predecessors(g);
}
