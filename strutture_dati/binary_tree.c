#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

Node *find(Node *tree, int k) {
    while (tree != NULL && tree->key != k) {
        if (k < tree->key) {
            tree = tree->sx;
        } else {
            tree = tree->dx;
        }
    }

    return tree;
}

Node *find_recursive(Node *tree, int k) {
    if (tree == NULL) {
        return NULL;
    } else if (k < tree->key) {
        return find_recursive(tree->sx, k);
    } else if (k > tree->key) {
        return find_recursive(tree->dx, k);
    }

    return tree;
}

Node *insert(Node *tree, int d) {
    int k = d;
    Node *r = malloc(sizeof(Node *));
    r->key = k;
    r->sx = NULL;
    r->dx = NULL;
    Node *padre = NULL;
    Node *n = tree;

    while (n != NULL) {
        padre = n;

        if (k < n->key) {
            n = n->sx;
        } else {
            n = n->dx;
        }
    }

    if (padre == NULL) {
        tree = r;
    } else if (k < padre->key) {
        padre->sx = r;
    } else {
        padre->dx = r;
    }

    return tree;
}

Node* insert_recursive(Node *tree, int d) {
    int k = d;

    if (tree == NULL) {
        tree = malloc(sizeof(Node *));
        tree->key = k;
        tree->sx = NULL;
        tree->dx = NULL;
    } else if (k < tree->key) {
        tree->sx = insert_recursive(tree->sx, d);
    } else {
        tree->dx = insert_recursive(tree->dx, d);
    }

    return tree;
}

Node *erase(Node *tree, int k) {
    Node *padre = NULL;
    Node *n = tree;

    while (n != NULL && n->key != k) {
        padre = n;

        if (k < n->key) {
            n = n->sx;
        } else {
            n = n->dx;
        }
    }

    if (n != NULL) {
        if (n->sx == NULL) {
            if (padre != NULL) {
                if (n->key < padre->key) {
                    padre->sx = n->dx;
                } else {
                    padre->dx = n->dx;
                }
            } else {
                tree = tree->dx;
            }
        } else if (n->dx == NULL) {
            if (padre != NULL) {
                if (n->key < padre->key) {
                    padre->sx = n->sx;
                } else {
                    padre->dx = n->sx;
                }
            } else {
                tree = tree->sx;
            }
        } else {
            Node *t = n;
            Node *m = n->sx;

            while (m->dx != NULL) {
                t = m;
                m = m->dx;
            }

            n->key = m->key;

            if (t == n) {
                n->sx = m->sx;
            } else {
                t->dx = m->sx;
            }
        }
    }

    return tree;
}

void printTree(Node *tree, int visit_type) {
    if (tree == NULL) {
        return;
    }

    switch (visit_type) {
        case 0:
            printf("%d ", tree->key);
            printTree(tree->sx, visit_type);
            printTree(tree->dx, visit_type);
            break;

        case 1:
            printTree(tree->sx, visit_type);
            printf("%d ", tree->key);
            printTree(tree->dx, visit_type);
            break;

        case 2:
            printTree(tree->sx, visit_type);
            printTree(tree->dx, visit_type);
            printf("%d ", tree->key);
            break;
    }
}
