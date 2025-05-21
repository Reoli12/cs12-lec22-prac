#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *get_iterative(LinkedList *list, int idx);

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

    Node *node_pointer = get(list_pointer, 1);
    printf("%i\n", node_pointer->data);
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