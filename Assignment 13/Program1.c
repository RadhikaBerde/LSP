/* 1. Write a program which creates 2 process as reader and writer and that processes should communicate with each other using FIFO. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{
   int iRet= 0;
   int fd = 0;
   char *path = "/tmp/mypipe";
   char Buffer[20];
   
   fd = mkfifo(path,0666);
   
   if(fd == 0)
   {
      printf("Unable to create named pipe\n");
      return -1;
   }
   
   
   iRet = fork();
   if(iRet == 0) // Writer process
   {
      printf("Inside writer process \n");
      printf("Writer is runnning and writing data into named pipe\n");
      fd = open(path,O_WRONLY);
      write(fd,"Marvellous",10);
      printf("Data successfully written in the pipe...\n");
      close(fd);
   }
   
   iRet = fork();
   if(iRet == 0) // Reader process
   {
      printf("Inside reader process \n");
      printf("Reader is runnning and reading the data from named pipe\n");
      fd = open(path,O_RDONLY);
      read(fd,Buffer,10);
      printf("Data successfully read from the pipe : %s\n", Buffer);
      close(fd);
   }
   
   return 0;
}
