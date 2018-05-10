/* Maze Solver utilizing graphs */
/* Felipe Scrochio Custódio */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define bool char
#define true 1
#define false 0

typedef struct VERTEX {

	/* VERTEX location */
	int id;
	/* content of VERTEX (1 or 0) */
	char value;
	/* number of edges */
	int edges;
	/* adjacency list */
	int* adjacents;
	/* discovered by search flag */
	bool discovered;
	/* distance used in search algorithms */
	int distance;
	/* predecessor */
	int parent;

} VERTEX; 

typedef struct graph {

	/* number of vertices */
	int size; 
	/* list of node references */
	VERTEX** content;

} Graph;

Graph* createGraph();
void addVERTEX(Graph *g, int content);
void add_edge(Graph* g, int start, int end);
void resetGraph(Graph *g);
void bfs(Graph *g, int start);