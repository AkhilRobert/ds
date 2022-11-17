#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node_t;

struct Node {
    int value;
    node_t *next;
};

node_t *head = NULL;

void insertFirst(int value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = value;
    node->next = head;
    head = node;
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
    int pos = 0;
    while (ptr != NULL) {
        printf("%d, %d\n", ptr->value, pos);
        ptr = ptr->next;
        pos++;
    }
}

node_t *findByValue(int value) {
    node_t *current = head;
    int pos = 0;

    // There is no items
    if (isEmpty()) {
        return NULL;
    }

    while (current->value != value) {
        if (current->next == NULL) {
            return NULL;
        }
        current = current->next;
        pos++;
    }

    printf("Found at the position %d", pos);

    return current;
}

node_t *findByPos(int pos_to_find) {
    node_t *current = head;
    node_t *found = NULL;
    int current_pos = 0;

    while (current_pos != pos_to_find) {
        if (current->next == NULL)
            return NULL;

        current = current->next;
        found = current;
        current_pos++;
    }

    return found;
}

void deleteAtPos(int pos) {
    node_t *current = head;
    node_t *previous = NULL;
    int current_pos = 0;

    if (isEmpty()) {
        return;
    }

    while (current_pos != pos) {
        if (current->next == NULL) {
            return;
        }
        previous = current;
        current = current->next;
        current_pos++;
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
    int current_pos = 0;

    new->value = element;

    if (isEmpty()) {
        return;
    }

    while (current_pos != pos) {
        if (current->next == NULL) {
            return;
        }
        previous = current;
        current = current->next;
        current_pos++;
    }

    if (previous)
        previous->next = new;
    else
        head = new;
    new->next = current;
}

int main() {
    insertFirst(12);
    insertFirst(14);
    insertFirst(15);
    insertFirst(16);
    display();
    insertAtPos(1, 2000);
    insertAtPos(1, 5000);
    insertAtPos(0, 333);
    deleteAtPos(1);
    deleteAtPos(1);
    insertAtPos(4, 4000);
    printf("==============\n");
    display();

    node_t *value = findByPos(2);
    if (value == NULL)
        printf("Not found\n");
    else
        printf("The current value is %d\n", value->value);

    return 0;
}
