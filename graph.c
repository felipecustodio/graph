/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>

// typedef int bool;
// enum {
//     false,
//     true
// };

typedef struct vertex {
    int id;
    char value;
    int out_degree;
    int* adjacents;
} Vertex;

typedef struct edge {
    int start;
    int end;
    char value;
} Edge;

typedef struct graph {
    int size;
    Vertex** vertices;
    Edge** edges;
    char** matrix;
} Graph;

void initGraph(Graph** g) {
    (*g) = (Graph*)malloc(sizeof(Graph));
    (*g)->size = 0;
    (*g)->vertices = NULL;
    (*g)->edges = NULL;
    (*g)->matrix = NULL;
}

void initVertex(Vertex** v) {
    (*v) = (Vertex*)malloc(sizeof(Vertex));
    (*v)->id = -1;
    (*v)->out_degree = 0;
    (*v)->adjacents = NULL;
}

void initEdge(Edge** e) {
    (*e)->start = -1;
    (*e)->end = -1;
}

void initMatrix(Graph** g) {
    int i, j;
    for (i = 0; i < (*g)->size; i++) {
        for (j = 0; j < (*g)->size; j++) {
            (*g)->matrix[i][j] = 0;
        }
    }
}

void listToMatrix(Graph** g) {
    int i, j;
    for (i = 0; i < (*g)->size; i++) {
        for (j = 0; j < (*g)->vertices[i]->out_degree; j++) {
            (*g)->matrix[i][(*g)->vertices[i]->adjacents[j]] = 1;
        }
    }
}

void addVertex(Graph *g, char value) {
	Vertex* v;
    initVertex(&v);

	g->vertices = (Vertex**)realloc(g->vertices,
        sizeof(Vertex*) * g->size + 1);

	v->value = value;
	v->id = g->size;

	g->vertices[g->size] = v;
	g->size += 1;
}

void addEdge(Graph* g, int start, int end) {
    Edge* e;
    initEdge(&e);
    e->start = start;
    e->end = end;

    int i, j;
    for (i = 0; i < g->size; i++) {
        if (g->vertices[i]->value == start) {
            // add end to adjacents
        } else if (g->vertices[i]->value == end) {
            // add start to adjacents
        }
    }
}

int main(int argc, char const *argv[]) {

    Graph* g;
    initGraph(&g);

    return 0;
}
