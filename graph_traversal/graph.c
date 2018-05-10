/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

// Initializers
void init_graph(Graph** g, int vertices) {
    int i, j;
    (*g) = (Graph*)malloc(sizeof(Graph));
    // initialize vertices
    (*g)->n_vertices = vertices;
    (*g)->vertices = (VERTEX**)malloc(sizeof(VERTEX*) * vertices);
    for (i = 0; i < vertices; i++) {
        (*g)->vertices[i] = (VERTEX*)malloc(sizeof(VERTEX));
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

void add_edge(Graph* g, int start, int end) {
    g->matrix[start][end] = 1;
}

void remove_edge(Graph** g, int start, int end) {
    (*g)->matrix[start][end] = 0;
}

void bfs(Graph* g, int start, int end) {

    printf("BFS between %d %d\n", start, end);

    int i, j;
    int current;
    // initialize queue (static)
    Queue* q = createQueue();
    // mark current as visited and add to queue
    g->vertices[start]->discovered = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        current = dequeue(q);
        printf("%d\n", current);

        // loop adjacents
        for () {
            if (!g->vertices[i]->discovered) {
                g->vertices[i]->discovered = 1;
                enqueue(q, i);
            }
        }
    }
}

void dfs(graph* g, int start, int end) {
    int i;
    printf("\n%d", start);
    g->vertices[start]->discovered = 1;
    for (i = 0; i < g->n_vertices; i++) {
        if (!g->vertices[i]->discovered && g->matrix[i][j]) {
            dfs(g, i, end);
        }
    }
}

void print_graph(Graph* g) {
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
