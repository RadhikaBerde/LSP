/* 1. Write a program in which parent process waits till its child process terminates. */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
   int iRet = 0;
   int cpid = 0;
   int Exit_status = 0;
   
   iRet = fork();
   
   if(iRet == 0)
   {
      execl("./ChildProcess", "NULL", NULL);
   }
   else
   {
      printf("Parent process is running with PID: %d\n", getpid());
      cpid = wait(&Exit_status);
      printf("Child process terminated having PID %d with exit status %d\n", cpid, Exit_status);
   }
   
   return 0;
}
