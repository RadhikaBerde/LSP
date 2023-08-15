/* 3. Write a program which creates such a process which accepts signal from terminal. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signal) 
{
    printf("Received signal: %d\n", signal);
}

int main() 
{
    int iRet = 0; 
    int iRet1 = 0;

    iRet = fork();

    if (iRet == 0) // Child process
    {  
        printf("Child process running with PID: %d\n", getpid());

        signal(SIGINT, sig_handler);  // Register signal handler

        while (1) 
        {
            sleep(1);  // Child process keeps running
        }
    } 
    else // Parent process
    {  
        printf("Parent process running with PID: %d\n", getpid());

        printf("Press Enter to send SIGINT to the child process...\n");
        getchar();  // Wait for Enter key

        // Send SIGINT signal to the child process
        iRet1 = kill(iRet, SIGINT);
        if (iRet1 == 0)
        {
            printf("SIGINT signal sent to child process\n");
        } 

        printf("Parent process is exiting\n");
    }

    return 0;
}
