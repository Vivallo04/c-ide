#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <malloc.h>

bool OnQuit = false;
int reserve_memory();
size_t get_total_memory();

/*
int main(void)
{
    int num = 0;
    int *num_ptr = &num;
    bool collecting = true;

    size_t memory_size = 1;
    void *reserve;
    reserve_memory(memory_size, &reserve);
    while (collecting)
    {
        printf("Collecting unused memory... %d\n", *num_ptr);
        //printf("Total memory in use: %zu bytes\n", reserve);
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

