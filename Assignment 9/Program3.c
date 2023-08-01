/* 3. Write a program which is used to print priority of process. */

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() 
{
    int priority = 0;
    int pid = 0;
    
    pid = getpid();
 
    // Get the priority of the current process
    priority = getpriority(PRIO_PROCESS, 0);

    if (priority == -1) 
    {
        printf("Error getting process priority");
        return 1;
    }

    printf("Priority of the current process (PID %d) is: %d\n", pid, priority);

    return 0;
}
