/* 5. Write a program which is used to get thread id inside its thread function. */

#include<stdio.h>
#include<pthread.h>


void * ThreadProc(void *ptr)
{
   pthread_t TID;
   
   printf("Inside Thread 1\n");
   
   TID = pthread_self();
   
   printf("Thread 1 is created successfully with TID : %ld\n", pthread_self());
   
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
   
   printf("Thread is created successfully with TID : %ld\n", pthread_self());
   
   pthread_join(TID, NULL);
   
   printf("End of main thread\n");
   
   return 0;
}
