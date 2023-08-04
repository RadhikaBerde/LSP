/* 1. Write a program which creates 4 number of threads and our main thread waits till all the threads terminates. */

#include<stdio.h>
#include<pthread.h>


void * ThreadProc1(void *ptr)
{
   printf("Inside Thread 1 \n");
}

void * ThreadProc2(void *ptr)
{
   printf("Inside Thread 2 \n");
}

void * ThreadProc3(void *ptr)
{
   printf("Inside Thread 3 \n");
}

void * ThreadProc4(void *ptr)
{
   printf("Inside Thread 4 \n");
}

int main()
{
   pthread_t TID1;
   pthread_t TID2;
   pthread_t TID3;
   pthread_t TID4;
   int iRet1 = 0;
   int iRet2 = 0;
   int iRet3 = 0;
   int iRet4 = 0;
   
   
   iRet1 = pthread_create(&TID1,
                          NULL,
                          ThreadProc1,
                          NULL);
                  
  if(iRet1 != 0)
  {
     printf("Unable to create thread 1\n");
     return -1;
  }
    
  iRet2 = pthread_create(&TID2,
                         NULL,
                         ThreadProc2,
                         NULL);
                  
  if(iRet2 != 0)
  {
     printf("Unable to create thread 2\n");
     return -1;
  }
  
  iRet3 = pthread_create(&TID3,
                         NULL,
                         ThreadProc3,
                         NULL);
                  
  if(iRet3 != 0)
  {
     printf("Unable to create thread 3\n");
     return -1;
  }
  
  iRet4 = pthread_create(&TID4,
                         NULL,
                         ThreadProc4,
                         NULL);
                  
  if(iRet4 != 0)
  {
     printf("Unable to create thread 4\n");
     return -1;
  }
  
  pthread_join(TID1, NULL);
  pthread_join(TID2, NULL);
  pthread_join(TID3, NULL);
  pthread_join(TID4, NULL);
   
  printf("End of main thread\n");
  
  return 0;
}
