#include <stdint.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node Node;
struct node {
    int data;
    Node *next;
};
    
typedef struct {
    Node *head;
    uint32_t size;
} LinkedList;

Node *get_recursive(LinkedList *list, int idx);
Node *get_next_node(Node *node, int target_idx, int curr_idx);
Node *get_iterative(LinkedList *list, int idx);
Node *insert_at(LinkedList *list, int idx, Node *new);

#endif

