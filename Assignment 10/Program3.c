/* 3 Write a program which creates single thread & we have to pass parameters to that thread through main thread. */


#include<stdio.h>
#include<pthread.h>

struct Student
{
   int iMarks;
   int iRoll_No;
   
};

void * ThreadProc(void* ptr)
{
   int iSum = 0;
   
   printf("Inside thread 1\n");
   
   typedef struct Student Student; 
   Student* sobj = (Student*)ptr;
   
   iSum = sobj->iMarks + sobj->iRoll_No;
   
   printf("Thread Result: %d\n", iSum);
}


int main()
{
   pthread_t TID;
   int iRet = 0;
   
   struct Student sobj;
   sobj.iMarks = 10;
   sobj.iRoll_No = 20;
   
   iRet = pthread_create(&TID,
                         NULL,
                         ThreadProc,
                         (void*)&sobj);
                         
    if(iRet != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %ld\n",TID);
    
    pthread_join(TID,NULL);
    
    printf("End of main thread\n");
    
    return 0;
}
