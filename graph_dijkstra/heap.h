/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>

#define LCHILD(x) 2 * x + 1
#define RCHILD(x) 2 * x + 2
#define PARENT(x) (x - 1) / 2

typedef struct HEAP_NODE {
    int id;
    int data;
} HEAP_NODE;

typedef struct MIN_HEAP {
    int size;
    HEAP_NODE* nodes;
} MIN_HEAP;

// swap two nodes
void swap(HEAP_NODE *n1, HEAP_NODE *n2);

// heapify to make sure the structure obeys the heap property
void heapify(MIN_HEAP *heap, int i);

// insert new node, following the heap property
void push_heap(MIN_HEAP *heap, int data, int id);

// delete root,replacing with the last node
void delete_heap_node(MIN_HEAP *heap);

// pop the root (smallest nodesent)
int pop_heap(MIN_HEAP *heap);
