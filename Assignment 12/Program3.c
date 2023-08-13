/* 3. Write a program which creates one child process, child process writes something in the unnamed pipe and parent process read the data 
from the pipe. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
   int iRet = 0;
   int FD[2];
   char Arr[] = "Radhika";
   char Buffer[20];
   
   pipe(FD);
   
   iRet = fork();
   
   if(iRet == 0)
   {
      printf("Child process is created successfully\n");
      close(FD[0]);
      write(FD[1],Arr,sizeof(Arr));
      printf("Child process writtern data into the PIPE successfully\n");
   }
   else
   {
      printf("Inside Parent Process \n");
      close(FD[1]);
      read(FD[0], Buffer, sizeof(Buffer));
      printf("Data in PIPE is : %s\n", Buffer);
      printf("Parent process read data from the PIPE successfully\n");
   }
   
   return 0;
   
}
