#pragma once

struct node {
    int key;
    struct node *sx;
    struct node *dx;
};
typedef struct node Node;

Node *find(Node *tree, int k);
Node *find_recursive(Node *tree, int k);
Node *insert(Node *tree, int d);
Node* insert_recursive(Node *tree, int d);
Node *erase(Node *tree, int k);

/*
    0 = preorder
    1 = inorder
    2 = postorder
*/
void printTree(Node *tree, int visit_type);
