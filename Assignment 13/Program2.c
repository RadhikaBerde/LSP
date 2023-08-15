/* 2. Write a program which creates child process and parent process will communicate with child process by sending signals. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void child_handler(int signal) 
{
    printf("Child process received signal %d\n", signal);
    
    if (signal == SIGINT)
    {
    	printf("received SIGINT\n");
    }
}

int main() 
{
    int iRet = 0;

    iRet = fork();

    if (iRet == 0)  // Child process
    {
        printf("Child process is running\n");
        signal(SIGINT, child_handler);

        while (1) 
        {
            sleep(1);  // Child process keeps running
        }
    } 
    else  // Parent process
    {
        printf("Parent process is running\n");

        sleep(2); // Wait for a moment before sending the signal

        printf("Sending signal to child process\n");
        kill(iRet, SIGINT);

        sleep(1); // Wait to see the child's response

        printf("Parent process is exiting\n");
    } 

    return 0;
}
