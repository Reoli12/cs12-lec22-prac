#include "linked_list.h"
#include <stddef.h>

Node *get_recursive(LinkedList *list, int idx) {
    Node *p = list->head;

    if (p == NULL) {
        return NULL;
    }

    return get_next_node(p, idx, 0);
}

Node *get_next_node(Node *node, int target_idx, int curr_idx) {

    if (node == NULL) { // NULL compares t pointer
        return NULL;
    }

    if (target_idx == curr_idx) {
        return node;
    }

    Node *p = node->next;
    return get_next_node(p, target_idx, curr_idx + 1);
}

Node *get_iterative(LinkedList *list, int idx) { // returns pointer to Node
    Node *p = list->head; // a node
    int n = 0;

    while (p != NULL) {
        if (n == idx) {
            return p;
        } 
        p = p->next; // go to next node
        n++;
    }
    return NULL;
}

Node *insert_at(LinkedList *list, int idx, Node *new) {

    if (idx < 0 || idx > list->size) {
        return NULL;
    }

    if (idx == 0) {
        Node *head = list->head;
        new->next = head;
        list->head = new;
        list->size++;
        return new;
    }

    Node *before = get_recursive(list, idx - 1);
    Node *idx_node = before->next;

    before->next = new;
    new->next = idx_node;
    list->size++;

    return new;
}