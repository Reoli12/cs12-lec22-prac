#include <stdint.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};
 
typedef struct {
    Node *head;
    uint32_t size;
} LinkedList;

