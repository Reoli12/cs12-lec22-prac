#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"  // your header with the declarations

// Utility to create a new node
Node *create_node(int data) {
    Node *n = malloc(sizeof(Node));
    if (!n) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->next = NULL;
    return n;
}

// Utility to print list
void print_list(LinkedList *list) {
    Node *p = list->head;
    printf("List (size: %u): ", list->size);
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList list = { .head = NULL, .size = 0 };

    // Insert at head (index 0)
    insert_at(&list, 0, create_node(10));  // 10
    print_list(&list);

    // Insert at tail (index 1)
    insert_at(&list, 1, create_node(20));  // 10 -> 20
    print_list(&list);

    // Insert in middle (index 1)
    insert_at(&list, 1, create_node(15));  // 10 -> 15 -> 20
    print_list(&list);

    // Insert at head again
    insert_at(&list, 0, create_node(5));   // 5 -> 10 -> 15 -> 20
    print_list(&list);

    // Insert out of bounds (too large)
    Node *bad = insert_at(&list, 99, create_node(999));
    if (bad == NULL) {
        printf("Insert at invalid index failed as expected.\n");
    }
    print_list(&list);

    return 0;
}