/* 5. Write a program which is used to yields our processor by using appropriate system call. */

#include <stdio.h>
#include <sched.h>

int main() 
{
    printf("Yield the processor \n");

    if (sched_yield() == -1) 
    {
        printf("Error yielding the processor");
        return -1;
    }

    printf("Processor yielded successfully\n");

    return 0;
}
