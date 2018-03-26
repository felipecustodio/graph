/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int instruction(char* input, char* command) {
    if (strcmp(input, command) == 0) {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[]) {

    char* command = (char*)malloc(sizeof(char) * 3);
    char directed, representation;
    int x, y, w; // vertices x,y, weight w
    int i, j;

    Graph* g = NULL;
    initGraph(&g);

    // create graph with given parameters
    scanf("%c %c %d %d", &directed, &representation, &x, &y);

    // initialize adjacency matrix
    g->representation = representation;
    if (g->representation == 'M') {
        initMatrix(&g, x);
    }

    // set graph type (directed or undirected)
    switch (directed) {
        case 'D':
            g->directed = 1;
            break;
        case 'G':
            break;
    }

    int start, end, weight;
    // read edges (start, end, weight)
    for (i = 0; i < y; i++) {
        scanf("%d %d %d", &start, &end, &weight);
        getchar();
        addVertex(&g, start);
        addVertex(&g, end);
        addEdge(&g, start, end, weight);
    }
    sortEdges(&g);

    while (scanf("%s ", command) != EOF) {
        if (instruction(command, "IG")) {
            printGraph(g);
        } else if (instruction(command, "VA")) {
            // print adjacency list of x
            scanf("%d", &x);
            printAdjacents(g, x);
        } else if (instruction(command, "AA")) {
            // add edge between x y with weight w
            scanf("%d %d %d", &x, &y, &w);
            addEdge(&g, x, y, w);
            sortEdges(&g);
        } else if (instruction(command, "RA")) {
            scanf("%d %d", &x, &y);
            removeEdge(&g, x, y);
        } else if (instruction(command, "IT")) {
            if (g->directed) {
                transpose(&g);
                printGraph(g);
            }
        } else if (instruction(command, "MP")) {
            findSmallestEdge(g);
        }
    }
    return 0;
}
