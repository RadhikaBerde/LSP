/* 4. Write a program which creates single thread it accepts one value from user & it return some value to the caller thread. */

#include<stdio.h>
#include<pthread.h>

struct Student
{
   int iMarks;
   int iRoll_No;
   
};

void * ThreadProc(void * ptr)
{
    int input = 0;
    int output = 0;
    
    typedef struct Student Student; 
    Student* sobj = (Student*)ptr;
    
    printf("Inside Thread 1\n");
    
    input =  (sobj->iMarks);
    output =  input * 2;
    sobj->iRoll_No = output;

}

int main()
{
    pthread_t TID;
    
    int iRet = 0;
    int iNo = 0;
    
    printf("Enter Marks : \n");
    scanf("%d", &iNo);
    
   struct Student sobj;
   sobj.iMarks = iNo;
   sobj.iRoll_No = 25;
   
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
   
   printf("Result from the thread: %d\n", sobj.iRoll_No);
   
   printf("End of main thread\n");
   
   return 0;
   
}
