/***********************************************/
/* SCC0216 - Modelagem Computacional em Grafos */
/* Felipe Scrochio Custódio - 9442688          */
/***********************************************/

#include "heap.h"

void swap(HEAP_NODE *n1, HEAP_NODE *n2) {
    HEAP_NODE temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heapify(MIN_HEAP *heap, int i) {
    int smallest = (LCHILD(i) < heap->size && heap->nodes[LCHILD(i)].data < heap->nodes[i].data) ? LCHILD(i) : i;
    if(RCHILD(i) < heap->size && heap->nodes[RCHILD(i)].data < heap->nodes[smallest].data) {
        smallest = RCHILD(i);
    }
    if(smallest != i) {
        swap(&(heap->nodes[i]), &(heap->nodes[smallest]));
        heapify(heap, smallest);
    }
}

void push_heap(MIN_HEAP *heap, int data, int id) {
    if(heap->size) {
        heap->nodes = realloc(heap->nodes, (heap->size + 1) * sizeof(HEAP_NODE));
    } else {
        heap->nodes = malloc(sizeof(HEAP_NODE));
    }

    HEAP_NODE nd;
    nd.data = data;
    nd.id = id;

    int i = (heap->size)++;
    while (i && nd.data < heap->nodes[PARENT(i)].data) {
        heap->nodes[i] = heap->nodes[PARENT(i)];
        i = PARENT(i);
    }
    heap->nodes[i] = nd;
}

void delete_heap_node(MIN_HEAP *heap) {
    if (heap->size) {
        heap->nodes[0] = heap->nodes[--(heap->size)];
        heap->nodes = realloc(heap->nodes, heap->size * sizeof(HEAP_NODE));
        heapify(heap, 0);
    } else {
        free(heap->nodes);
    }
}

int pop_heap(MIN_HEAP *heap) {
    int id = 0;
    if (heap->size) {
        id = heap->nodes[0].id;
    } else {
        id = -1;
    }
    delete_heap_node(heap);
    return id;
}
