// Queue (Static)
// Felipe Scrochio Custódio - 9442688
#ifndef QUEUE_H
#define QUEUE_H

#define SIZE 100
// #define item Vertex*
#define item int

typedef struct queue Queue;
Queue* createQueue();
int isFull(Queue *q);
int isEmpty(Queue *q);
int enqueue(Queue *q, item n);
int dequeue(Queue *q);
int size(Queue *q);

#endif
