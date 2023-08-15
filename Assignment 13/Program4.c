/* 4. Write a program which accepts user defined signals from terminal. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signal) 
{
    printf("Received user-defined signal: %d\n", signal);
}

int main() 
{
    int iRet = 0; 
    int signalNum = 0;
    
    printf("Enter the signal number you want to send: ");
    scanf("%d", &signalNum);

    iRet = fork();

    if (iRet == 0) // Child process
    {  
        printf("Child process running with PID: %d\n", getpid());

        signal(signalNum, sig_handler); 

        while (1) 
        {
            sleep(1);  // Child process keeps running
        }
    } 
    else // Parent process
    {  
        printf("Parent process running with PID: %d\n", getpid());

        printf("Press Enter to send signal %d to the child process...\n", signalNum);
        getchar();  // Consume the newline character
        getchar();  // Wait for Enter key
        
        // Send the user-defined signal to the child process
        kill(iRet, signalNum);
        
        sleep(1); // Wait to see the child's response
        
        printf("Parent process is exiting\n");
    }

    return 0;
}
