#pragma once

struct list_node {
    int key;
    struct list_node *next;
};
typedef struct list_node ListNode;

ListNode *find_pos(ListNode *list, int i);
ListNode *find_unsorted(ListNode *list, int k);

// only if the list is sorted
ListNode *find_sorted(ListNode *sorted_list, int k);
ListNode *insert_sorted(ListNode *sorted_list, int d);
ListNode *erase_sorted(ListNode *sorted_list, int k);

void printList(ListNode *list);
