/* 4. Write a program which creates 2 threads , and by using appropriate synchronization technique avoid the scheduling Problem. */

#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t counter_mutex;

void* ThreadProc1(void* ptr) 
{
    printf("Inside Thread 1\n");

    for (int i = 0; i < 100; i++) 
    {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }

}

void* ThreadProc2(void* ptr) 
{
    printf("Inside Thread 2\n");

    for (int i = 0; i < 100; i++) 
    {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
}

int main() 
{
    pthread_t TID1; 
    pthread_t TID2;
    int iRet1;
    int iRet2;

    pthread_mutex_init(&counter_mutex, NULL);

    iRet1 = pthread_create(&TID1, 
                           NULL, 
                           ThreadProc1, 
                           NULL);
    if (iRet1 != 0) 
    {
        printf("Unable to create thread 1\n");
        return -1;
    }

    iRet2 = pthread_create(&TID2, 
                           NULL, 
                           ThreadProc2, 
                           NULL);
    if (iRet2 != 0) 
    {
        printf("Unable to create thread 2\n");
        return -1;
    }

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    pthread_mutex_destroy(&counter_mutex);

    printf("Value of counter is %d\n", counter);
    printf("End of main thread\n");

    return 0;
}
