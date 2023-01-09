#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MINSIZE 5
#define EMPTYTOP -1

typedef struct StackRecord *stack;

struct StackRecord {
    int capacity;
    int top;
    int *array;
};

stack createStack(int size) {
    stack s;

    if (size < MINSIZE) {
        printf("Size of stack should be greater than %d", MINSIZE);
        return NULL;
    }

    // Size of the pointer cannot be found during the compile time
    // so using sizeof(pointer) is bad
    // s = (queue)malloc(sizeof(stack)); --> This is bad
    s = (stack)malloc(sizeof(struct StackRecord));
    s->capacity = size;
    s->top = EMPTYTOP;
    s->array = (int *)malloc(sizeof(int) * size);

    return s;
}

bool isEmpty(stack s) {
    return s->top == EMPTYTOP;
}

bool isFull(stack s) {
    return s->top == s->capacity - 1;
}

void push(stack s, int element) {
    if (isFull(s)) {
        printf("The stack is full\n");
    } else {
        s->top++;
        s->array[s->top] = element;
        printf("The element %d is pushed to the stack\n", element);
    }
}

void pop(stack s) {
    if (isEmpty(s)) {
        printf("The stack is full\n");
    } else {
        printf("The element %d is removed from the stack\n", s->array[s->top]);
        s->top--;
    }
}

void peek(stack s) {
    if (isEmpty(s)) {
        printf("The stack is empty");
    } else {
        printf("The top element is %d\n", s->array[s->top]);
    }
}

void printStack(stack s) {
    int limit = s->top;
    while (limit >= 0) {
        printf("%d\n", s->array[limit]);
        limit--;
    }
}

int main() {
    stack s = createStack(6);
    push(s, 12);
    push(s, 12);
    push(s, 12);
    push(s, 12);
    push(s, 120);
    push(s, 160);
    pop(s);
    peek(s);
    printStack(s);
    pop(s);
    peek(s);
    printStack(s);
}
