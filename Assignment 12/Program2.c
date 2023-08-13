/* 2. Write a program which is used to create 2 processes and that 2 processes can communicate with each other by 
using the concept of shared memory. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
  int iRet1 = 0;
  int iRet2 = 0;
  int shmid = 0;
  int shmsize = 100;
  int key = 1234;
  char *ptr = NULL;
  
  printf("Application is running \n");
  
  shmid = shmget(key, shmsize, IPC_CREAT | 0666);
  
  printf("Shared memory allocated successfully..\n");
  
  ptr = shmat(shmid, NULL, 0);
   
  if(ptr != NULL)
  {
     printf("Shared memory attached successfully\n");
  }
  
  iRet1 = fork();
  
  if(iRet1 == 0)
  {
     printf("Process1 is created sucessfully\n");
     
     strcpy(ptr, "Jay Ganesh..!\n");
     printf("Child1 writtern data successfully...\n");
     shmdt(shmid);
  }
  
  iRet2 = fork();
  
  if(iRet2 == 0)
  {
     printf("Process2 is created sucessfully\n");
     printf("Child2 read data successfully...\n");
     printf("Data is : %s \n", ptr);
     shmdt(shmid);
  }
  
  printf("Application is done\n");
  
  return 0;
  
}  
