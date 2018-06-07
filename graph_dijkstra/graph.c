/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"

#define DEBUG 0
#define IF_DEBUG if(DEBUG)

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
        // initialize weights for dijkstra
        (*g)->vertices[i]->weight = INT_MAX;
    }
    // initialize adjacency matrix
    (*g)->matrix = (int**)malloc(sizeof(int*) * vertices);
    for (i = 0; i < vertices; i++) {
        (*g)->matrix[i] = (int*)malloc(sizeof(int) * vertices);
        for (j = 0; j < vertices; j++) {
            (*g)->matrix[i][j] = -1;
        }
    }
}

// add edge between nodes 'start' and 'end' with weight 'weight'
void add_edge(GRAPH* g, int start, int end, int weight) {
    g->matrix[start][end] = weight;
    // g->matrix[end][start] = weight;
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

// Dijkstra's shortest path
void dijkstra(GRAPH* g, int src, int dest) {
    int i;
    int smallest = 0;
    int parent = dest;
    int* path = NULL;

    // reset vertices
    for (i = 0; i < g->n_vertices; i++) {
        g->vertices[i]->discovered = 0;
        g->vertices[i]->parent = -1;
        g->vertices[i]->weight = INT_MAX;
    }

    // initialize heap and insert source node
    IF_DEBUG printf("Initializing heap\n");
    MIN_HEAP *queue = (MIN_HEAP*)malloc(sizeof(MIN_HEAP));
    queue->size = 0;

    IF_DEBUG printf("Adding source node to heap\n");
    g->vertices[src]->weight = 0;
    push_heap(queue, 0, src);

    while (queue->size > 0) {

        // get id for smallest cost vertex
        smallest = pop_heap(queue);
        IF_DEBUG printf("Smallest is %d with weight %d\n", smallest, g->vertices[smallest]->weight);
        // set vertex as visited
        g->vertices[smallest]->discovered = 1;

        // iterate over its' neighbors
        for (i = 0; i < g->n_vertices; i++) {
            // check if edge exists
            IF_DEBUG printf("Checking edge %d->%d with weight %d\n", smallest, i, g->matrix[smallest][i]);
            if (g->matrix[smallest][i] > -1) {
                // check if node i was visited
                if (g->vertices[i]->discovered == 0) {
                    IF_DEBUG printf("Node %d is not visited\n", i);
                    // relax edge
                    // check if current weight is better
                    IF_DEBUG printf("Is %d > %d?\n", g->vertices[i]->weight, g->vertices[smallest]->weight + g->matrix[smallest][i]);
                    if (g->vertices[i]->weight > g->vertices[smallest]->weight + g->matrix[smallest][i]) {
                        IF_DEBUG printf("Relax edge!\n");
                        g->vertices[i]->weight =  g->vertices[smallest]->weight + g->matrix[smallest][i];
                        IF_DEBUG printf("%d discovered %d\n", smallest, i);
                        g->vertices[i]->parent = smallest;
                        // push node i to heap
                        IF_DEBUG printf("Pushing %d to heap\n", i);
                        push_heap(queue, g->vertices[i]->weight, i);
                    }
                }
            }
        }
    }
}

// Print path
void print_path(GRAPH* g, int src, int dest) {
	int i, j;
	int* path = NULL;

    i = 0;
	j = dest;
    VERTEX* aux = g->vertices[dest];

    j = aux->id;
	while(j != -1) {
		path = (int*)realloc(path, sizeof(int) * (i + 1));
		path[i] = j;
		j = aux->parent;
		if (j != -1) {
			aux = g->vertices[j];
			i++;
		}
	}

	if (i > 0 && path[i] == src) {
		for(j = i; j >= 0; j--) {
			printf("%d ", path[j]);
		}
	}

	printf("\n");
}
