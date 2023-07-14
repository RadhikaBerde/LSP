/*2. Write a program which accepts file name & mode from user and then open that file in specified mode */

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc , char * argv[])
{
   int fd = 0;
   int Mode = 0;
   
   printf("Usage : Name_of_Executable Name_of_file Mode_of_open \n");
   
   if(argc != 3)
   {
      printf("Invalid number of arguments\n");
      return -1;
   }
   
   if(strcmp(argv[2] , "Read") == 0 )
   {
      Mode = O_RDONLY;
      printf("File opened in Read Mode\n");
   }
   else if(strcmp(argv[2] , "Write") == 0 )
   {
      Mode = O_WRONLY;
      printf("File opened in Write Mode\n");
   }
   else if(strcmp(argv[2] , "ReadWrite") == 0 )
   {
      Mode = O_RDWR;
      printf("File opened in Read Write Mode\n");
   }
   else
   {
      Mode = O_RDONLY;
      printf("File opened in Read Mode\n");
   }
   
   fd = open(argv[1], Mode);
   
   if(fd == -1)
   {
      printf("Unable to open file\n");
      return -1;
   }
   else
   {
      printf("File opened sucessfully with fd : %d\n", fd);
   }

   close(fd);
   
   return 0;
}
