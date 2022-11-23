#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueRecord queue_t;
typedef struct Node node_t;

struct Node {
    int value;
    node_t *next;
};

struct QueueRecord {
    node_t *front, *rear;
};

bool isEmpty(queue_t *q) {
    return q->rear == NULL;
}

void makeEmpty(queue_t *q) {
    q->front = q->rear = NULL;
}

queue_t *createQueue(int capacity) {
    queue_t *q = NULL;
    q = (queue_t *)malloc(sizeof(queue_t));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue_t *q, int element) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = element;

    if (!q->rear) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }

    printf("Element %d added to the queue\n", element);
}

void dequeue(queue_t *q) {
    if (!q->front) {
        printf("Queue underflow\n");
        return;
    }

    node_t *queue = q->front;
    q->front = q->front->next;

    if (!q->front)
        q->rear = NULL;

    free(queue);
}

void display(queue_t *q) {
    if (isEmpty(q)) {
        printf("There is no elements in the queue\n");
        return;
    }

    node_t *current = q->front;

    while (current != NULL) {
        printf("%d - ", current->value);
        current = current->next;
    }
    printf("\n");
}

void front(queue_t *q) {
    printf("The front is %d\n", q->front->value);
}

void rear(queue_t *q) {
    printf("The rear is %d\n", q->rear->value);
}

int main() {
    queue_t *q = createQueue(5);
    enqueue(q, 12);
    enqueue(q, 36);
    enqueue(q, 48);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
}
