/* 3. Write a program which is used to print priority of process. */

#include <stdio.h>
#include <sys/resource.h>

int main() 
{
    int ret = 0;
 
    // Get the priority of the current process
    ret = getpriority(PRIO_PROCESS, 0);


    printf("Priority of the current process is: %d\n", ret);

    return 0;
}
