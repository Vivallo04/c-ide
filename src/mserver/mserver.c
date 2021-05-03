#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <malloc.h>
#include "node.h"

// Add a threading library compatible with C and C++
#include <pthread.h>
#include <unistd.h>

// Declare static variables
bool OnQuit = false;

int reserve_memory(size_t bytes, void *reserve);
size_t get_total_memory(void);
void create_linked_list(void);

/*
// Entry Point
int main(void)
{
    int num = 0;
    int *num_ptr = &num;
    bool collecting = true;

    create_linked_list();
    size_t memory_size = 100000;
    void *reserve;

    reserve_memory(memory_size, &reserve);
    while (collecting)
    {
        printf("Collecting unused memory... %d\n", *num_ptr);
        *num_ptr += 1;
        sleep(1);

        if (OnQuit)
        {
            collecting = false;
        }
    }
    free(reserve);
    return 0;
}
*/

int reserve_memory(size_t bytes, void *reserve)
{
    reserve = malloc(bytes);
    if (reserve)
    {
        printf("Allocated %zu bytes from %lx to %lx\n", bytes, reserve, (bytes + reserve));
    } else if (reserve == NULL) {
        printf("Error in allocation\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void create_linked_list(void)
{
    struct Node *head = malloc(sizeof(struct Node));
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
}

