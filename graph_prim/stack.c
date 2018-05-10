/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_init(STACK* s) {
    s->size = 0;
}

int stack_top(STACK* s) {
    if (s->size == 0) {
        return -1;
    }
    return s->data[s->size-1];
}

int push(STACK* s, int d) {
    if (s->size < STACK_MAX)
        s->data[s->size++] = d;
    else
        return -1;
}

int pop(STACK* s) {
        int item = stack_top(s);
        s->size--;
        return item;
}
