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
    g->matrix[end][start] = weight;
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
