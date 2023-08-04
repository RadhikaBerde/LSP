/*1. Write a program which is used to create simple thread by using pthread library. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc(void *ptr)
{
   printf("Inside thread\n");
}

int main()
{
  pthread_t TID;
  int iRet = 0;
  
  iRet = pthread_create(&TID,
                        NULL,
                        ThreadProc,
                        NULL);
                       
  if(iRet != 0)
  {
     printf("Unable to create thread\n");
     return -1;
  }
  
  printf("Thread is created sucessfully with ID : %ld\n", TID);
  
  return 0;
  
}
