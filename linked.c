#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node_t;

struct Node {
    int value;
    int pos;
    node_t *next;
};

node_t *head = NULL;

void create(int value) {
    node_t *result = (node_t *)malloc(sizeof(node_t));
    result->value = value;
    result->next = head;
    if (head == NULL) {
        result->pos = 0;
    } else {
        result->pos = head->pos + 1;
    }
    head = result;
}

bool isEmpty() { return head == NULL; }

void deleteFirst() {
    if (isEmpty()) {
        printf("There is no items in the list");
        return;
    }
    node_t *temp = head;
    head = temp->next;
    free(temp);
}

void display() {
    node_t *ptr = head;
    while (ptr != NULL) {
        printf("%d, %d\n", ptr->value, ptr->pos);
        ptr = ptr->next;
    }
}

node_t *findAtPos(int pos) {
    node_t *current = head;

    // There is no items
    if (isEmpty()) {
        return NULL;
    }

    while (current->pos != pos) {
        if (current->next == NULL) {
            return NULL;
        } else {
            current = current->next;
        }
    }

    return current;
}

void deleteAtPos(int pos) {
    node_t *current = head;
    node_t *previous = NULL;

    if (isEmpty()) {
        return;
    }

    while (current->pos != pos) {
        if (current->next == NULL) {
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }

    if (current == head) {
        head = head->next;
    } else {
        previous->next = current->next;
    }
}

void insertAtPos(int pos, int element) {
    node_t *current = head;
    node_t *previous = NULL;
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new->value = element;
    new->pos = head->pos + 1;

    if (isEmpty()) {
        return;
    }

    while (current->pos != pos) {
        if (current->next == NULL) {
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }

    previous->next = new;
    new->next = current;
}

int main() {
    create(12);
    create(14);
    create(15);
    create(16);
    display();
    insertAtPos(1, 2000);
    insertAtPos(4, 4000);
    printf("==============\n");
    display();
    return 0;
}
