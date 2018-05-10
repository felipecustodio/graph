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
    int v1, v2; // start, end of edge
    int i;

    // initialize new graph
    Graph* g = NULL;

    // read and create graph edges
    scanf("%d %d", &v, &e);
    init_graph(&g, v);
    for (i = 0; i < e; i++) {
        scanf("%d %d", &v1, &v2);
        add_edge(g, v1, v2);
    }

    // find path between two nodes
    while (scanf("%d %d", &v1, &v2) != EOF) {
        bfs(g, v1, v2);
    }

    return 0;
}
