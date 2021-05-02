#ifndef GARBGECOLLECTOR_NODE_H
#define GARBGECOLLECTOR_NODE_H
#include <stdio.h>

typedef struct Node
{
    char name;
    int value;
    int *address;
    unsigned int size;
    struct Node *next;
} head;

// Declare methods
void print_list_nodes(struct Node *node);
void append_node(struct Node **head, int data);
void push_node(struct Node **head, int data);

#endif //GARBGECOLLECTOR_NODE_H
