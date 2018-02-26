/* Maze Solver utilizing graphs */
/* Felipe Scrochio Custódio */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define bool char
#define true 1
#define false 0

typedef struct vertex {

	/* vertex location */
	int id;
	/* content of vertex (1 or 0) */
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

} Vertex; 

typedef struct graph {

	/* number of vertices */
	int size; 
	/* list of node references */
	Vertex** content;

} Graph;

Graph* createGraph();
void addVertex(Graph *g, int content);
void addEdge(Graph* g, int start, int end);
void resetGraph(Graph *g);
void bfs(Graph *g, int start);