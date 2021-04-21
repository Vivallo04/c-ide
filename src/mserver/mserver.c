#include <stdio.h>
#include <stdbool.h>

//Four types of storage duration in C: automatic, static
// thread and allocated.

/**
 * Automatic: The ones declared within a block or as a function parameter.
 * Static: The lifetime of these objetcs is the entire execution of the program
 * and their stored value is initialized prior to program startup.
 * Thread: Used in concurrent programming.
 * Allocated: Dynamically allocated memory (chapter 6).
 */

void swap(int *a, int *b);
void increment(void);

struct S
{
    int i;
    double d;
    char c;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void increment(void)
{
    static unsigned int counter = 0;
    counter++;
    printf("%d\n", counter);
}


int main(void)
{
    int a = 2;
    int b = 5;
    bool flag = true;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    for (int i = 0; i < 10; i++) {
        increment();
    }

    unsigned char bad_buff[sizeof(struct S)];
    _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];

    struct S *bad_s_ptr = (struct S *)bad_buff;
    struct S *good_s_ptr = (struct S *)good_buff;
    return 0;
}

