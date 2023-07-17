/* 3. Write a program which accepts two directory names from user and move all files from source directory to destination directory. */

#include<stdio.h>

int main(int argc, char *argv[])
{ 
   int Ret = 0;
   
   printf("Usage : Directory1_Name Directory2_Name\n");
   
   if(argc != 3)
   {
      printf("Invalid number of arguments\n");
      return -1;
   }
   
   Ret = rename(argv[1], argv[2]);
   
   if(Ret == 0)
   {
     printf("Files moved successfully\n");
   }
   else
   {
     printf("Unable to move files\n");
   }
   
   return 0;
   
}
   
