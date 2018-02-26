// Queue
// @author: Felipe Scrochio Custódio

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct queue {
	int content[SIZE];
	int begin;
	int end;
	int total;
} Queue;

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

int enqueue(Queue *q, int item) {
	if (!isFull(q)) {
		q->content[q->end] = item;
		q->end = (q->end + 1) % SIZE;
		q->total += 1;
		return 1;
	} else {
		return 0;
	}
}

int dequeue(Queue *q) {
	if (!isEmpty(q)) {
		int item = q->content[q->begin];
		q->begin = (q->begin + 1) % SIZE;
		q->total -= 1;
		return item;
	} else {
		return -1;
	}
}

int size(Queue *q) {
	return q->total;
}