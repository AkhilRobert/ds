#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

typedef struct Node node_t;

struct Node {
    int key;
    node_t *left, *right;
};

node_t *createNode(int key) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

node_t *insert(node_t *root, int key) {
    // Same as checking root == NULL
    if (!root)
        return createNode(key);

    if (root->key > key)
        root->left = insert(root->left, key);
    if (root->key < key)
        root->right = insert(root->right, key);

    return root;
}

void display(node_t *root, int space) {
    if (!root)
        return;

    space += SIZE;

    display(root->right, space);
    for (int i = SIZE; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    display(root->left, space);
}

int main() {
    node_t *root = NULL;
    root = insert(root, 50);
    root = insert(root, 100);
    root = insert(root, 500);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 11);
    root = insert(root, 120);
    display(root, 0);
    return 0;
}
