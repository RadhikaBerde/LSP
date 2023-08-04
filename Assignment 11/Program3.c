/* 3. Write a program which is used to predict the problem due to lack of synchronization. */

#include<stdio.h>
#include<pthread.h>

int counter = 0;

void * ThreadProc1(void *ptr)
{

   int i;
   
   printf("Inside Thread 1 \n");
    
   for(i=0;i<100;i++)
   {
      counter++;
   }
   
   printf("Value of counter in Thread 1 %d\n", counter);
}

void * ThreadProc2(void *ptr)
{
   int i = 0;
   
   printf("Inside Thread 2 \n");
   
   for(i=0;i<100;i++)
   {
      counter++;
   }
   
   printf("Value of counter in Thread 2 %d\n", counter);
}

int main()
{
   pthread_t TID1;
   pthread_t TID2;
   int iRet1 = 0;
   int iRet2 = 0;

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
  
  pthread_join(TID1, NULL);
  pthread_join(TID2, NULL);
  
  printf("Value of counter is %d\n", counter);
  printf("End of main thread\n");
  
  return 0;
}
