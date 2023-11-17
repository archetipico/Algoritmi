#include <stdio.h>
#include "lista_lineare.c"

int main(void) {
    Node *list = malloc(sizeof(Node *));
    Node *next = malloc(sizeof(Node *));
    list->key = 2;
    list->next = next;
    next->key = 3;

    Node *found = find(list, 3);
    printf("%d\n", found->key);

    list = insert(list, 7);
    list = insert(list, 5);
    printList(list);

    list = erase(list, 5);
    printList(list);

    free(list);

    return 0;
}
