/* 5. Write a program which creates two process as sender and receiver in which sender process send signal to reciever process. */

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sig_handler(int signal)
{
  printf("Received signal : %d\n", signal);
}

int main()
{
   int iRet1 = 0;
   int iRet2 = 0;
   
   iRet1 = fork();
   if(iRet1 == 0)
   {
      printf("Inside receiver process %d\n",getpid());
      signal(SIGINT, sig_handler); 
      while (1) 
      {
          sleep(1);  // Keep running to receive signal
      }
   }
   
   iRet2 = fork();
   if(iRet2 == 0)
   {
      printf("Inside sender process %d\n",getpid());
      sleep(1);
      kill(iRet1, SIGINT);
      printf("Sender process sent SIGINT signal to receiver process.\n");
   }
   
    wait(NULL);
    wait(NULL);

   printf("Parent process is exiting\n");   
   return 0;
}
