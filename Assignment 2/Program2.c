/* 2. Write a program which accepts filename from user & write string in that file. */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
   int fd = 0;
   char Buffer[100] = "India";
   
   printf("Usage : Name_of_Executable Name_of_file\n");
   
   if(argc != 2)
   {
     printf("Invalid numberof arguments \n");
     return -1;
   }
   
   fd = open(argv[1], O_WRONLY);
   
   if(fd == -1)
   {
      printf("Unable to open file \n");
      return -1;
   }
   else
   {
      printf("File is opened successfully with fd : %d\n", fd);
   }
   
   write(fd,Buffer,5);

   close(fd);
   
   return 0;
  
}
