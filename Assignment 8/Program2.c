/* 2. Write a program which creates 3 level process hierarchy where process 1 creates process 2 and it internally creates process 3. */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
  int iRet1 = 0;
  int iRet2 = 0;
 
  //Process 1 
  printf("Process 1 PID : %d \n", getpid());
  
  iRet1 = fork();
  
  if(iRet1 == 0)
  {
     // Process 2 (Child of Process 1)
     printf("Child says : PID of child process Process 2 is : %d \n", getpid());
     printf("Child says : PID of parent process Process 1 is : %d \n", getppid());
     
     iRet2 = fork();
     
     if(iRet2 == 0)
     {
        // Process 3 (Child of Process 2)
        printf("Child says : PID of child process Process 3 is : %d \n", getpid());
        printf("Child says : PID of parent process Process 2 is : %d \n", getppid());
     }
     
  }
  
  return 0;
}
