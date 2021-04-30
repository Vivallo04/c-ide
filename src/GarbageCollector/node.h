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
} node;

#endif //GARBGECOLLECTOR_NODE_H
