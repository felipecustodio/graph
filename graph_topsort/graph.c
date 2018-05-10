/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"

// Initializers
void initGRAPH(GRAPH** g, int vertices) {
    int i, j;
    (*g) = (GRAPH*)malloc(sizeof(GRAPH));
    // initialize vertices
    (*g)->n_vertices = vertices;
    (*g)->vertices = (Vertex**)malloc(sizeof(Vertex*) * vertices);
    for (i = 0; i < vertices; i++) {
        (*g)->vertices[i] = (Vertex*)malloc(sizeof(Vertex));
        (*g)->vertices[i]-> id = i;
        // color 0 - white (undiscovered)
        (*g)->vertices[i]->color = 0;
        (*g)->vertices[i]->parent = -1;
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


void addEdge(GRAPH* g, int start, int end) {
    g->matrix[start][end] = 1;
}


void removeEdge(GRAPH** g, int start, int end) {
    (*g)->matrix[start][end] = 0;
}


void printGRAPH(GRAPH* g) {
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


void dfs_visit(GRAPH* g, STACK* s, int node) {
    int i;
    // set color to GRAY
    g->vertices[node]->color = 1;
    // iterate through adjacents of 'node'
    for (i = 0; i < g->n_vertices; i++) {
        if (g->matrix[node][i] == 1) {
            g->vertices[i]->parent = node;
            if (g->vertices[i]->color == 0) {
                dfs_visit(g, s, i);
            }
        }
    }
    // set color to BLACK
    g->vertices[node]->color = 2;
    // push 'node' to stack
    push(s, node);
}


void dfs(GRAPH* g, STACK* s) {
    int i;
    for (i = 0; i < g->n_vertices; i++) {
        // check if color is WHITE (undiscovered)
        if (g->vertices[i]->color == 0) {
            dfs_visit(g, s, i);
        }
    }
}


void topsort(GRAPH* g, STACK* s) {
    int i;
    int node;
    dfs(g, s);
    for (i = s->size; i > 0; i--) {
        node = pop(s);
        printf("%d ", node);
    }
}
