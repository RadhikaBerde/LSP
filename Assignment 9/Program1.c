/*1. Write a program which creates new process which is responsible to write all file names which are present on Desktop in demo file which should be newly created. */

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>

int main()
{
   int iRet = 0;
   int fd = 0;
   DIR *dp = NULL;
   struct dirent * entry = NULL;
    
   iRet = fork();
   
   if(iRet == 0)
   {
      printf("Inside child process\n");
    
      dp = opendir("Desktop");
    
      if(dp == NULL)
      {
        printf("Unable to open directory \n");
        return -1;
      }
      
      fd = creat("demo.txt", O_RDWR);
      
      while((entry = readdir(dp)) != NULL)
      {
         write(fd , entry->d_name, strlen(entry->d_name));
         write(fd, " ", 1);
      }
      
      close(fd);
      closedir(dp);
   
    }
    
    return 0;
    
 }

