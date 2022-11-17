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

void display() {
    node_t *current = head;
    while (current != NULL) {
        printf("%d - ", current->value);
        current = current->next;
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
    return 0;
}
