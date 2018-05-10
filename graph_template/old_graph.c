/* Maze Solver utilizing graphs */
/* Felipe Scrochio Custódio */

#include <stdio.h>
#include <stdlib.h>

#define bool char
#define true 1
#define false 0
#define SIZE 100

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

typedef struct queue {

	VERTEX* content[SIZE];
	int begin;
	int end;
	int total;

} Queue;


/* queue definition and functions */
Queue* createQueue() {
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if (q != NULL) {
		q->begin = 0;
		q->end = 0;
		q->total = 0;
	}
	return q;
}

int isFull(Queue *q) {
	return (q->total == SIZE);
}

int isEmpty(Queue *q) {
	return (q->total == 0);
}

int enqueue(Queue *q, VERTEX* item) {
	if (!isFull(q)) {
		q->content[q->end] = item;
		q->end = (q->end + 1) % SIZE;
		q->total += 1;
		return 1;
	} else {
		return 0;
	}
}

VERTEX* dequeue(Queue *q) {
	if (!isEmpty(q)) {
		VERTEX* item = q->content[q->begin];
		q->begin = (q->begin + 1) % SIZE;
		q->total -= 1;
		return item;
	} else {
		return NULL;
	}
}

int size(Queue *q) {
	return q->total;
}

/* graph functions */
Graph* createGraph() {
	Graph *g = (Graph*)malloc(sizeof(Graph));
	g->content = NULL;
	g->size = 0;
	return g;
}

void addVERTEX(Graph *g, int content) {
	VERTEX* new = (VERTEX*)malloc(sizeof(VERTEX));
	/* increase VERTEX list of graph */
	g->content = (VERTEX**)realloc(g->content, sizeof(VERTEX*) * g->size + 1);
	/* insert new VERTEX with specified content */
	new->value = content;
	new->edges = 0;
	new->adjacents = NULL;
	new->id = g->size;
	g->content[g->size] = new;
	g->size += 1;
}

void add_edge(Graph* g, int start, int end) {
	/* start node, end node */
	/* add VERTEX to start adjacency list */
	/* access start VERTEX, enlarge array of adjacents by 1*/
	g->content[start]->adjacents = (int*)realloc(g->content[start]->adjacents, sizeof(int) * g->content[start]->edges + 1);
	/* add end VERTEX to adjacency list of start VERTEX */
	g->content[start]->adjacents[g->content[start]->edges] = end;
	/* increase number of edges */
	g->content[start]->edges += 1;
	/* add VERTEX to end adjacency list */
	/* access end VERTEX, enlarge array of adjacents by 1*/
	g->content[end]->adjacents = (int*)realloc(g->content[end]->adjacents, sizeof(int) * g->content[end]->edges + 1);
	/* add start VERTEX to adjacency list of start VERTEX */
	g->content[end]->adjacents[g->content[end]->edges] = start;
	/* increase number of edges */
	g->content[end]->edges += 1;
}

void sortEdges(Graph *g) {
	int i, j, k;
	int aux;
	for (i = 0; i < g->size; i++) {
		for (j = 1; j < g->content[i]->edges - 1; j++) {
			for (k = 0; k < g->content[i]->edges; k++) {
				if (g->content[i]->adjacents[k] > g->content[i]->adjacents[k + 1]) {
					aux = g->content[i]->adjacents[k];
					g->content[i]->adjacents[k] = g->content[i]->adjacents[k + 1];
					g->content[i]->adjacents[k + 1] = aux;
				}
			}  
		} 
	}
}

void resetGraph(Graph *g) {
	int i;
	for (i = 0; i < g->size; i++) {
		g->content[i]->discovered = false;
		g->content[i]->distance = 0;
		g->content[i]->parent = -1;
	}
}

void dfs(Graph *g, int start) {
	
}

void bfs(Graph *g, int start) {
	/* start = index */
	/* reset graph and create queue */
	int i;
	/* parent VERTEX */
	VERTEX* u = NULL;
	/* current VERTEX */
	int v;
	resetGraph(g);
	Queue *q = createQueue();
	enqueue(q, g->content[start]);
	while (!isEmpty(q)) {
		u = dequeue(q);
		for (i = 0; i < u->edges; i++) {
			v = u->adjacents[i];
			if (g->content[v]->discovered == false) {
				g->content[v]->discovered = true;
				g->content[v]->distance = u->distance + 1;
				g->content[v]->parent = u->id;
				enqueue(q, g->content[v]);
			} 
		}	
	}
}

void findPath(Graph *g, int start, int end, int col) {
	
	int i, j, lineBreak;
	bool inPath;
	int size = 0;
	int* path = NULL;
	/* get destination VERTEX */
	VERTEX* current = g->content[end];
	/* iterate until we reach the starting point */
	while (current->id != g->content[start]->id) {
		path = (int*)realloc(path, sizeof(int) * size + 1);
		path[size] = current->id;
		size++;
		current = g->content[current->parent];
	}

	/* print path reversed */
	printf("Path:\n");
	for (i = size; i >= 0; i--) {
		printf("[%d]->", path[i]);
	}
	printf("\nPath size:\n%d\n", size);

	printf("Solved Maze:\n");
	lineBreak = 0;
	for (i = 0; i < g->size; i++) {
		inPath = false;
		for (j = 0; j < size; j++) {
			if (g->content[i]->id == path[j]) {
				printf("x ");
				lineBreak++;
				inPath = true;
			}
		}
		if (!inPath) {
			printf("%d ", g->content[i]->value);
			lineBreak++;
		}
		if (lineBreak == col) {
			printf("\n");
			lineBreak = 0;
		}
	}

}

int main(int argc, char const *argv[]) {
	
	int i, j;
	int menu;
	int row, col;
	int start, end;
	int** maze;

	/* create graph */
	Graph *g = createGraph();

	scanf("%d %d", &row, &col);

	/* read maze and insert vertices on the graph */
	maze = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) {
		maze[i] = (int*)malloc(sizeof(int) * col);
		for (j = 0; j < col; j++) {
			scanf("%d", &maze[i][j]);
			addVERTEX(g, maze[i][j]);
		}
	}

	/* scan graph for 0s, create edges between them */
	int counter = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (maze[i][j] == 0) {
				/* check right */
				if (j + 1 < col) {
					if (maze[i][j + 1] == 0) {
						add_edge(g, counter, counter + 1);
					}
				}
				/* check down */
				if (i + 1 < row) {
					if (maze[i + 1][j] == 0) {
						add_edge(g, counter, counter + col);
					}
				}
 			}
 			/* add counter of visited vertices */
 			counter++;
		}
	}

	scanf("%d %d", &start, &end);

	sortEdges(g);
	bfs(g, start);
	findPath(g, start, end, col);

	/*printf("Please choose a search method: \n");
	printf("\t1) Breadth First Search (BFS)\n");
	printf("\t2) Depth First Search (DFS)\n");

	scanf("%d", &menu);

	if (menu == 1) {
		bfs(g, start);
	}  else if (menu == 2) {
		dfs(g, start);
	} else {
		printf("You didn't choose a valid option!");
	}*/

	return 0;
}