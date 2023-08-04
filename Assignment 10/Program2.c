/* 2. Write a program which creates 2 thread, first thread print numbers from 1-500 and other thread prints number from 500-1. */

#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{     
      printf("Inside Thread 1\n");
      
      int i = 0; 
      
      for(i=1;i<=500;i++)
      {
         printf("%d\n", i);
      }
}

void * ThreadProc2(void *ptr)
{     
      printf("Inside Thread 2\n");
      
      int i = 500;
      
      for(i=500;i>=1;i--) 
      {
         printf("%d\n", i);
      }
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
       printf("Unable to create thread\n");
       return -1;
   }
   
   printf("Thread 1 is created successfully with ID : %ld\n", TID1);
   
   iRet2 = pthread_create(&TID2,
                         NULL,
                         ThreadProc2,
                         NULL);
                         
   if(iRet2 != 0)
   {
       printf("Unable to create thread\n");
       return -1;
   }
   
   printf("Thread 2 is created successfully with ID : %ld\n", TID2);
   
   pthread_join(TID1,NULL);
   pthread_join(TID2,NULL);
   
   printf("End of main thread\n");
   
   return 0;
                         
}
  
