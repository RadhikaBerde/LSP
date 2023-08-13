/* 1. Write a program which is used to create unnamed pipe. Parent process creates new child process and both the processes will 
communicate with each other. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int FD[2];
    int iRet = 0;
    char Arr[] = "India is my country";
    char Buffer[512];

    pipe(FD);

    iRet = fork();

    if(iRet == 0)   // Child process
    {
        printf("Child process scheduled for writing into pipe\n");
        close(FD[0]);
        write(FD[1],Arr,strlen(Arr));
        exit(0);
    }
    else      // Parent Process
    {
        printf("Parent process scheduled for reading from pipe\n");
        close(FD[1]);
        read(FD[0],Buffer,sizeof(Buffer));
        printf("Data from PIPE is : %s\n",Buffer);
    }
    
    return 0;
}


