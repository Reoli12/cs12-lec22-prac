#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *get_recursive(LinkedList *list, int idx);
Node *get_next_node(Node *node, int target_idx, int curr_idx);

int main() {
    Node *a = malloc(sizeof(Node));
    Node *b = malloc(sizeof(Node));
    Node *c = malloc(sizeof(Node));

    a->data = 1;
    b->data = 2;
    c->data = 3;

    a->next = b;
    b->next = c;
    c->next = NULL;

    // Create the list
    LinkedList list;
    list.head = a;
    list.size = 3;

    // test
    LinkedList *list_pointer = &list;

    Node *node_pointer = get_recursive(list_pointer, 1);
    printf("%i\n", node_pointer->data);
}

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