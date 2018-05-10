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

// Prim's algorithm for MST
void prim(GRAPH* g) {
	int i, j, k;
    int count, predecessor, child, min;

    // initialize set of reached vertices
	VERTEX* reached = (VERTEX*)malloc(sizeof(VERTEX) * g->n_vertices);
    // initialize all as undiscovered and without parents
    for (i = 0; i < g->n_vertices; i++) {
        reached[i].discovered = 0; // set as undiscovered
        reached[i].parent = -1; // set parent as -1
    }

    // visit first node 0
	reached[0].discovered = 1;

    // traverse reached nodes set
    // J -> K
	for (i = 0; i < g->n_vertices - 1; i++) {
		min = 9999;
        // traverse all graph nodes
		for (j = 0; j < g->n_vertices; j++) {
            // check if node is in reached sets
            if (reached[j].discovered == 1) {
                // traverse all adjacent nodes
				for (k = 0; k < g->n_vertices; k++) {
                    // check if edge from J to K exists
                    if (g->matrix[j][k] > -1) {
                        // check if cost from J to K is smaller than current min
                        if (g->matrix[j][k] < min) {
                            // check if node K is undiscovered
                            if (reached[k].discovered == 0) {
                                min = g->matrix[j][k];
                                predecessor = j;
                                child = k;
                            }
                        }
                    }
                }
            }
        }
        // minimum edge weight found: print edge
        // predecessor discovered child
    	reached[child].parent = predecessor;

        // set K of edge (J,K) as visited
    	reached[child].discovered = 1;

        // print edge (as if it was inserted on MST sorted)
    	if(predecessor > child) {
    		printf("(%d,%d) ", child, predecessor);
    	} else {
    		printf("(%d,%d) ", predecessor, child);
    	}
	}
    printf("\n");
}
