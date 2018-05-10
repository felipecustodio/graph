/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void init_graph(Graph** g) {
    (*g) = (Graph*)malloc(sizeof(Graph));
    (*g)->n_vertices = 0;
    (*g)->n_edges = 0;
    (*g)->vertices = NULL;
    (*g)->edges = NULL;
    (*g)->matrix = NULL;
}

void initVERTEX(VERTEX** v) {
    (*v) = (VERTEX*)malloc(sizeof(VERTEX));
    (*v)->id = -1;
    (*v)->out_degree = 0;
    (*v)->adjacents = NULL;
    (*v)->value = 0;
}

void initEdge(Edge** e) {
    (*e) = (Edge*)malloc(sizeof(Edge));
    (*e)->start = -1;
    (*e)->end = -1;
    (*e)->weight = 0;
}

void initMatrix(Graph** g, int size) {
    int i, j;
    // init matrix to zeroes
    (*g)->matrix = (char**)malloc(sizeof(char*) * size);
    for (i = 0; i < size; i++) {
        (*g)->matrix[i] = (char*)malloc(sizeof(char) * size);
        for (j = 0; j < size; j++) {
            (*g)->matrix[i][j] = -1;
        }
    }
}

void addVERTEX(Graph** g, int value) {
	VERTEX* v;
    initVERTEX(&v);

    int i;
    // discover if VERTEX already exists
    for (i = 0; i < (*g)->n_vertices; i++) {
        if ((*g)->vertices[i]->value == value) {
            return;
        }
    }

    // allocate new VERTEX
	(*g)->vertices = (VERTEX**)realloc((*g)->vertices,
        sizeof(VERTEX*) * (*g)->n_vertices + 1);

    // set new VERTEX values
	v->value = value;
	v->id = (*g)->n_vertices;

    // add new VERTEX to VERTEX list
	(*g)->vertices[(*g)->n_vertices] = v;
	(*g)->n_vertices += 1;
}

void add_edge(Graph** g, int start, int end, int weight) {
    switch ((*g)->representation) {
        case 'M':
            add_edge_Matrix(g, start, end, weight);
            break;
        case 'L':
            add_edge_List(g, start, end, weight);
            break;
    }
}

void add_edge_List(Graph** g, int start, int end, int weight) {
    // initialize
    Edge* e;
    initEdge(&e);
    e->start = start;
    e->end = end;
    e->weight = weight;

    // check if edge already exists in list before adding
    int i;
    for (i = 0; i < (*g)->n_edges; i++) {
        if ((*g)->edges[i]->start == start && (*g)->edges[i]->end == end) {
            return;
        } else if ((*g)->edges[i]->start == end && (*g)->edges[i]->end == start && !(*g)->directed) {
            return;
        }
    }

    // allocate memory for new edge
    (*g)->edges = (Edge**)realloc((*g)->edges,
        sizeof(Edge*) * (*g)->n_edges + 1);
    (*g)->edges[(*g)->n_edges] = e;
    (*g)->n_edges += 1;

    /**************************/
    /* Assuming that input given to
    create node is value, not id */
    /**************************/
    for (i = 0; i < (*g)->n_vertices; i++) {
        // search for node with value start or end
        if ((*g)->vertices[i]->value == start) {
            // add 'end' to 'start' adjacency list
            (*g)->vertices[i]->adjacents = (int*)realloc((*g)->vertices[i]->adjacents,
                sizeof(int) * (*g)->vertices[i]->out_degree + 1);
            (*g)->vertices[i]->adjacents[(*g)->vertices[i]->out_degree] = start;
            (*g)->vertices[i]->out_degree += 1;
        // if graph is not directed, add 'start' to 'end' list
        // otherwise, it's start->end
        } else if (((*g)->vertices[i]->value == end) && !(*g)->directed) {
            // add 'start' to 'end' adjacency list
            (*g)->vertices[i]->adjacents = (int*)realloc((*g)->vertices[i]->adjacents,
                sizeof(int) * (*g)->vertices[i]->out_degree + 1);
            (*g)->vertices[i]->adjacents[(*g)->vertices[i]->out_degree] = end;
            (*g)->vertices[i]->out_degree += 1;
        }
    }
}

void add_edge_Matrix(Graph** g, int start, int end, int weight) {
    // initialize
    Edge* e;
    initEdge(&e);
    e->start = start;
    e->end = end;
    e->weight = weight;

    // allocate memory for new edge
    (*g)->edges = (Edge**)realloc((*g)->edges,
        sizeof(Edge*) * (*g)->n_edges + 1);
    (*g)->edges[(*g)->n_edges] = e;
    (*g)->n_edges += 1;

    // set edge as existing in matrix
    (*g)->matrix[start][end] = weight;
    if (!(*g)->directed) {
        (*g)->matrix[end][start] = weight;
    }
}

void remove_edge(Graph** g, int start, int end) {
    switch ((*g)->representation) {
        case 'M':
            remove_edge_Matrix(g, start, end);
            break;
        case 'L':
            remove_edge_List(g, start, end);
            break;
    }
}

void remove_edge_List(Graph** g, int start, int end) {
    int i;
    for (i = 0; i < (*g)->n_vertices; i++) {
        // search for node with value start or end
        if ((*g)->vertices[i]->value == start) {
            // remove 'end' from 'start' adjacency list

        // if graph is not directed, don't remove 'start' from 'end' list
        // else, remove
        } else if (((*g)->vertices[i]->value == end) && !(*g)->directed) {
            // add 'start' to 'end' adjacency list
        }
    }
}

void remove_edge_Matrix(Graph** g, int start, int end) {
    int i;

    // remove on matrix
    (*g)->matrix[start][end] = -1;
    if (!(*g)->directed) {
        (*g)->matrix[end][start] = -1;
    }

    // logical removal
    for (i = 0; i < (*g)->n_edges; i++) {
        if ((*g)->edges[i]->start == start && (*g)->edges[i]->end == end) {
            (*g)->edges[i]->weight = 999; // INF
        }
        if ((*g)->edges[i]->start == end && (*g)->edges[i]->end == start && !(*g)->directed) {
            (*g)->edges[i]->weight = 999; // INF
        }
    }
}

void sortEdges(Graph** g) {
	int i, j, k;
	int aux;
	for (i = 0; i < (*g)->n_vertices; i++) {
		for (j = 1; j < (*g)->vertices[i]->out_degree - 1; j++) {
			for (k = 0; k < (*g)->vertices[i]->out_degree; k++) {
				if ((*g)->vertices[i]->adjacents[k] > (*g)->vertices[i]->adjacents[k + 1]) {
					aux = (*g)->vertices[i]->adjacents[k];
					(*g)->vertices[i]->adjacents[k] = (*g)->vertices[i]->adjacents[k + 1];
					(*g)->vertices[i]->adjacents[k + 1] = aux;
				}
			}
		}
	}
}

void transpose(Graph **g) {
    int i, aux;
    for (i = 0; i < (*g)->n_edges; i++) {
        aux = (*g)->edges[i]->start;
        (*g)->edges[i]->start = (*g)->edges[i]->end;
        (*g)->edges[i]->end = aux;
    }

    switch ((*g)->representation) {
        case 'M':
            transpose_Matrix(g);
            break;
        case 'L':
            transpose_List(g);
            break;
    }
}

void transpose_List(Graph **g) {

}

void transpose_Matrix(Graph** g) {
    int i, j;
    for (i = 0; i < (*g)->n_vertices; i++) {
        for (j = 0; j < (*g)->n_vertices; j++) {
            if ((*g)->matrix[j][i] == -1) {
              printf(". ");
            } else {
              printf("%d ", (*g)->matrix[j][i]);
            }
        }
        printf("\n");
    }
}

void print_graph(Graph* g) {
    switch (g->representation) {
        case 'M':
            print_graph_Matrix(g);
            break;
        case 'L':
            print_graph_List(g);
            break;
    }
}

void print_graph_List(Graph* g) {
    VERTEX* current = NULL;
    int i, j;
    // go through vertices
    for (i = 0; i < g->n_vertices; i++) {
        current = g->vertices[i];
        printf("%d. ", current->id);
        // go through adjacency list
        for (j = 0; j < g->vertices[i]->out_degree; j++) {
            printf("%d() ", g->vertices[i]->adjacents[j]);
        }
        printf("\n");
    }
}

void print_graph_Matrix(Graph* g) {
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

void printAdjacents(Graph* g, int VERTEX) {
    switch (g->representation) {
        case 'M':
            printAdjacencyMatrix(g, VERTEX);
            break;
        case 'L':
            printAdjacencyList(g, VERTEX);
            break;
    }
}

void printAdjacencyMatrix(Graph* g, int VERTEX) {
    int i;
    for (i = 0; i < g->n_vertices; i++) {
        if (g->matrix[VERTEX][i] > -1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void printAdjacencyList(Graph* g, int VERTEX) {
    int i;
    VERTEX* current = NULL;
    for (i = 0; i < g->n_vertices; i++) {
        if (g->vertices[i]->value == VERTEX) {
            current = g->vertices[i];
        }
    }
    for (i = 0; i < current->out_degree; i++) {
        printf("%d ", current->adjacents[i]);
    }
    printf("\n");
}

void findSmallestEdge(Graph* g) {
    int i;
    int min = g->edges[0]->weight;
    int aux;
    Edge* smallest = NULL;
    for (i = 0; i < g->n_edges; i++) {
        if (g->edges[i]->weight < min) {
            min = g->edges[i]->weight;
            smallest = g->edges[i];
        }
    }
    if (!g->directed) {
        if (smallest->start > smallest->end) {
            printf("%d %d\n", smallest->end, smallest->start);
        } else {
            printf("%d %d\n", smallest->start, smallest->end);
        }
    } else {
        printf("%d %d\n", smallest->start, smallest->end);
    }
}
