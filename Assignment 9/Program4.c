/* 4. Write a program which is used to increate priority by 5. */

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() 
{
    int pid = 0;
    int priority = 0;
    int Ret = 0;
    
    pid = getpid();

    // Get the current priority of the process
    priority = getpriority(PRIO_PROCESS, pid);

    if (priority == -1)
    {
        printf("Error getting process priority");
        return -1;
    }

    printf("Current priority of the process is: %d\n", pid, priority);

    // Increase the priority by 5
    Ret = setpriority(PRIO_PROCESS, pid, priority + 5);
    if (Ret == -1)
    {
        printf("Error setting process priority");
        return -1;
    }

    // Get the updated priority
    priority = getpriority(PRIO_PROCESS, pid);

    if (priority == -1) 
    {
        printf("Error getting process priority");
        return 1;
    }

    printf("Updated priority of the process (PID %d) is: %d\n", pid, priority);

    return 0;
}
