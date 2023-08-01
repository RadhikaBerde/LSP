/* 4 Write a Program which creates 2 processes as process2 & process3 and our parent process terminates till both the process terminates. */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main()
{
   int iRet2 = 0;
   int iRet3 = 0;
   int iRet4 = 0;
   int cpid = 0;
   int Exit_status = 0;
   
   // Process 1 
   
   printf("PID of Process 1 is : %d\n", getpid());
   
   // Create Process 2
   iRet2 = fork();
   
   if(iRet2 == 0)
   {
      printf("PID of Process 2 is : %d\n", getpid());
      printf("PID of Parent Process 1 is : %d\n", getppid());
   }
   else
   {
      // Create Process 3
      iRet3 = fork();
   
      if(iRet3 == 0)
      {
         printf("PID of Process 3 is : %d\n", getpid());
         printf("PID of Parent Process is : %d\n", getppid());
      }
      else
      {
          cpid = wait(&Exit_status);
          printf("Child process terminated having PID %d with exit status %d\n",cpid,Exit_status);
          cpid = wait(&Exit_status);
          printf("Child process terminated having PID %d with exit status %d\n",cpid,Exit_status);
      }
     }
   
   return 0;
}
