/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "graph.h"

int main(int argc, char const *argv[]) {

    STACK* s; // stack for topological sorting
    int v, e; // number of vertices, edges
    int v1, v2; // vertices to create edge
    int i;

    // initialize new graph
    GRAPH* g = NULL;

    // read and create graph edges
    scanf("%d %d", &v, &e);
    initGRAPH(&g, v);
    for (i = 0; i < e; i++) {
        scanf("%d %d", &v1, &v2);
        addEdge(g, v1, v2);
    }

    // topological sorting
    stack_init(s);
    topsort(g, s);

    return 0;
}
