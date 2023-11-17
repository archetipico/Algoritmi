#include <stdio.h>
#include <stdlib.h>
#include "lista_lineare.h"

ListNode *find_pos(ListNode *list, int i) {
    ListNode *p = list;
    
    while (p != NULL && i > 0) {
        p = p->next;
        i--;
    }

    return p;
}

ListNode *find_unsorted(ListNode *list, int k) {
    ListNode *p = list;

    while (p != NULL && p->key != k) {
        p = p->next;
    }

    return p;
}

ListNode *find_sorted(ListNode *sorted_list, int k) {
    ListNode *p = sorted_list;

    while (p != NULL && p->key != k) {
        p = p->next;
    }

    if (p == NULL || p->key > k) {
        return NULL;
    }

    return p;
}

ListNode *insert_sorted(ListNode *sorted_list, int d) {
    int k = d;
    ListNode *p = sorted_list;
    ListNode *prev = NULL;

    while (p != NULL && p->key < k) {
        prev = p;
        p = p->next;
    }

    ListNode *r = malloc(sizeof(ListNode *));
    r->key = k;
    r->next = p;

    if (prev == NULL) {
        sorted_list = r;
    } else {
        prev->next = r;
    }

    return sorted_list;
}

ListNode *erase_sorted(ListNode *sorted_list, int k) {
    ListNode *p = sorted_list;
    ListNode *prev = NULL;
    
    while (p != NULL && p->key < k) {
        prev = p;
        p = p->next;
    }

    if (p != NULL && p->key == k) {
        if (prev == NULL) {
            sorted_list = sorted_list->next;
        } else {
            prev->next = p->next;
        }
    }

    return sorted_list;
}

void printList(ListNode *list) {
    ListNode *p = list;

    while (p->next != NULL) {
        printf("%d -> ", p->key);
        p = p->next;
    }

    if (p != NULL) {
        printf("%d\n", p->key);
    }
}
