/* 4. Write a program which is used to increase priority by 5. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main() 
{
    int ret = 0;
    
    // Get the current priority of the process
    ret = getpriority(PRIO_PROCESS, 0);

    printf("Current priority of the process is: %d\n", ret);

    // Increase the priority by 5
    nice(-5);

    // Get the updated priority
    ret = getpriority(PRIO_PROCESS, 0);

    printf("Updated priority of the process is: %d\n", ret);

    return 0;
}




   

