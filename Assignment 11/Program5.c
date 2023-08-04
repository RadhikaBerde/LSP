/* 5. Write a program which creates 2 threads by using pthread API, where 1 thread counts number of capital characters from demo.txt 
file and other thread counts number of small character from same file. */

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>

void * ThreadProc1(void *ptr)
{          
    char Buffer[512];
    int iCnt = 0;
    int iRet = 0;
    int i = 0;
    int fd = 0;
    
    printf("Inside Thread 1\n");
       
    fd = open("demo.txt",O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet ; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of capital characters are : %d\n",iCnt);

    close(fd);
}

void * ThreadProc2(void *ptr)
{           
    char Buffer[512];
    int iCnt = 0;
    int iRet = 0;
    int i = 0;
    int fd = 0;
    
    printf("Inside Thread 2\n");
       
    fd = open("demo.txt",O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet ; i++)
        {
            if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
            {
                iCnt++;
            }
        }
    }

    printf("Number of small characters are : %d\n",iCnt);

    close(fd);
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
  
