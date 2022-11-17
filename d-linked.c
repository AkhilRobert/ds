#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node node_t;

struct Node {
    int value;
    node_t *next, *prev;
};

node_t *head = NULL;

void insertFirst(int value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = value;
    node->prev = NULL;
    node->next = head;
    if (head != NULL)
        head->prev = node;
    head = node;
}

bool isEmpty() { return head == NULL; }

void deleteAtPos(int pos) {
    node_t *current = head;
    node_t *prev_node;
    int current_pos = 0;

    while (current_pos != pos) {
        if (current->next == NULL) {
            printf("Not found at the position.\n");
            return;
        }

        current = current->next;
        current_pos++;
    }

    if (current == head) {
        head = head->next;
        head->prev = NULL;
    } else {
        prev_node = current->prev;
        prev_node->next = current->next;

        if (current->next != NULL)
            current->next->prev = prev_node;
    }

    free(current);
}

void insertAtPos(int pos, int value) {
    node_t *current = head;
    int current_pos = 0;

    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->value = value;

    while (current_pos != pos) {
        if (current->next == NULL) {
            printf("Position overflow");
            return;
        }

        current = current->next;
        current_pos++;
    }

    node->prev = current->prev;
    node->next = current;
    if (current->prev != NULL) {
        current->prev->next = node;
    } else {
        head = node;
    }
    current->prev = node;
}

void display() {
    node_t *current = head;
    int pos = 0;
    while (current != NULL) {
        printf("(i: %d, v: %d) - ", pos, current->value);
        current = current->next;
        pos++;
    }
    printf("\n");
}

int main() {
    insertFirst(12);
    insertFirst(13);
    insertFirst(14);
    insertFirst(15);

    display();

    deleteAtPos(1);
    deleteAtPos(2);

    display();

    insertAtPos(1, 300);
    insertAtPos(1, 300);
    insertAtPos(0, 70000);
    insertAtPos(2, 6000);

    display();

    insertAtPos(3, 222);
    display();

    return 0;
}
