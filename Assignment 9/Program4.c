/* 4. Write a program which is used to increate priority by 5. */

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() 
{
    int ret = 0;
    
    // Get the current priority of the process
    ret = getpriority(PRIO_PROCESS, 0);

    printf("Current priority of the process is: %d\n", ret);

    // Increase the priority by 5
    ret = nice(5);

    // Get the updated priority
    ret = getpriority(PRIO_PROCESS, 0);

    printf("Updated priority of the process is: %d\n", ret);

    return 0;
}


   

