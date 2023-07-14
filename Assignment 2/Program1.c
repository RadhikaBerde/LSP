/* 1. Write program which accept file name from user & read whole file. */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc , char *argv[])
{
   int fd   = 0;
   int iRet = 0;
   char Buffer[20] = {'\0'};
   
   printf("Usage : Name_of_Executable Name_of_file \n");
   
   if(argc != 2)
   {
     printf("Invalid number of arguments\n");
     return -1;
   }
   
   fd = open(argv[1] , O_RDONLY);
   
   if(fd == -1)
   {
      printf("Unable to open file\n");
      return -1;
   }
   else
   {
      printf("File opened successfully with fd : %d\n", fd);
   }
   
   printf("Data from File :- \n");
   
   while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
   {
        write(1,Buffer,iRet);
   }
   
   return 0;
}

