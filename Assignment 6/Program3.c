/* 3. Write a program which accepts directory name & File name from user & create file in that directory. */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc , char *argv[])
{
   char filepath[20]  = {'\0'};
   int iRet = 0;
   int fd = 0;

   printf("Usage : Executable_Name Directory_Name File_Name\n");
   
   if(argc != 2)
   {
      printf("Invalid number of arguments\n");
      return -1;
   }
   
   iRet = mkdir(argv[1], 0777);
   if(iRet == -1)
   {
      printf("Unable to create Directory\n");
      return -1;
   }
   else
   {
      printf("Directory created successfully\n");
   }
   
   sprintf(filepath, "%s/%s", argv[1] , argv[2]);
   
   fd = creat(filepath,0777);
   
   if(fd == -1)
   {
      printf("Unable to create file\n");
      return -1;
   }
   
   printf("File created successfully\n");
   
   close(fd);
   
   return 0;
}
