/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main(int argc, char const *argv[]) {

    int v, e; // number of vertices, edges
    int v1, v2; // vertices to create edge
    int w; // edge weight
    int src, dest; // desired path
    int i;

    // initialize new graph
    GRAPH* g = NULL;

    // read and create graph edges
    scanf("%d %d", &v, &e);
    init_graph(&g, v);
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        add_edge(g, v1, v2, w);
    }

    while (scanf("%d %d", &src, &dest) != EOF) {
        dijkstra(g, src, dest);
        print_path(g, src, dest);
    }

    return 0;
}
