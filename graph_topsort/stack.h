/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#ifndef _STACK_H_
#define _STACK_H_

#define STACK_MAX 100

typedef struct Stack {
    int data[STACK_MAX];
    int size;
} STACK;

void stack_init(STACK *S);
int stack_top(STACK *S);
int push(STACK *S, int d);
int pop(STACK *S);

#endif
