/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Initializers
void initGraph(Graph** g, int vertices) {
    int i, j;
    (*g) = (Graph*)malloc(sizeof(Graph));
    // initialize vertices
    (*g)->n_vertices = vertices;
    (*g)->vertices = (Vertex**)malloc(sizeof(Vertex*) * vertices);
    for (i = 0; i < vertices; i++) {
        (*g)->vertices[i] = (Vertex*)malloc(sizeof(Vertex));
        (*g)->vertices[i]-> id = i;
        (*g)->vertices[i]->discovered = 0;
    }
    // initialize adjacency matrix
    (*g)->matrix = (char**)malloc(sizeof(char*) * vertices);
    for (i = 0; i < vertices; i++) {
        (*g)->matrix[i] = (char*)malloc(sizeof(char) * vertices);
        for (j = 0; j < vertices; j++) {
            (*g)->matrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int start, int end) {
    g->matrix[start][end] = 1;
}

void removeEdge(Graph** g, int start, int end) {
    (*g)->matrix[start][end] = 0;
}

void printGraph(Graph* g) {
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
