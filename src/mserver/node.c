#include "node.h"
#include <stdlib.h>

// Get the list printed out
void print_list_nodes(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d\n", node -> value);
        node = node -> next;
    }
}

// Insert a Node at the start
void push_node(struct Node **head, int data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node -> value = data;
    new_node -> next = (*head);
    (*head) = new_node;
}

// Insert at the end
void append_node(struct Node **head, int data)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node -> value = data;
    new_node -> next = NULL;

    while (last -> next != NULL)
    {
        last = last -> next;
    }
    last -> next = new_node;
}
