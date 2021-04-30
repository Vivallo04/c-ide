#
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

int main(void)
{
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head -> value = 1;
    append_node(&head, 2);
    append_node(&head, 3);
    append_node(&head, 4);
    append_node(&head, 5);
    append_node(&head, 6);
    append_node(&head, 7);
    append_node(&head, 8);
    append_node(&head, 9);
    append_node(&head, 10);
    push_node(&head, 0);
    print_list_nodes(head);
    return 0;

}
