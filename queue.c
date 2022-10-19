#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueRecord *queue;

struct QueueRecord {
    int rear, front, capacity;
    int *array;
};

bool isEmpty(queue q) { return q->rear == -1 && q->front == -1; }

bool isFull(queue q) { return q->rear == q->capacity - 1; }

void makeEmpty(queue q) {
    q->front = -1;
    q->rear = -1;
}

queue createQueue(int capacity) {
    queue q;

    if (capacity < 5) {
        printf("Queue cannot be less than 5 elements\n");
        return NULL;
    }

    q = (queue)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->capacity = capacity;
    q->array = (int *)malloc(sizeof(int) * capacity);

    return q;
}

void enqueue(queue q, int element) {
    if (isFull(q)) {
        printf("Queue overflow \n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    printf("Element %d added to the queue\n", element);
    q->rear++;
    q->array[q->rear] = element;
}

void dequeue(queue q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue underflow");
        return;
    }

    printf("Element %d is removed from the queue\n", q->array[q->front]);
    q->front++;
}

void display(queue q) {
    if (isEmpty(q)) {
        printf("There is no elements in the queue\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->array[i]);
    }
}

void front(queue q) { printf("The front is %d", q->array[q->front]); }

void rear(queue q) { printf("The rear is %d", q->array[q->rear]); }

int main() {
    queue q = createQueue(5);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 16);
    display(q);
    dequeue(q);
    display(q);
    enqueue(q, 307);
    front(q);
    rear(q);
    makeEmpty(q);
    display(q);
}
