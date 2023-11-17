#include <stdio.h>
#include "binary_tree.c"

int main(void) {
    Node *tree = malloc(sizeof(Node *));
    tree->key = 5;
    tree = insert(tree, 3);
    tree = insert(tree, 11);
    tree = insert(tree, 5);
    tree = insert_recursive(tree, 1);
    tree = insert_recursive(tree, 4);
    tree = insert(tree, 9);
    printTree(tree, 0);
    printf("\n");
    printTree(tree, 1);
    printf("\n");
    printTree(tree, 2);
    printf("\n\n");

    Node *found = find(tree, 11);
    Node *found_rec = find_recursive(tree, 11);
    printTree(found, 0);
    printf("\n");
    printTree(found_rec, 0);
    printf("\n");

    tree = erase(tree, 11);
    tree = erase(tree, 3);
    printTree(tree, 0);
    printf("\n");

    free(tree);

    return 0;
}
