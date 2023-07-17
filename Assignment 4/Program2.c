/* 2. Write a program which accepts directory name from user & create new directory of that name. */

#include<stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  int Ret = 0;
  
  printf("Usage : Executable_Name Directory_Name \n");
  
   if(argc != 2)
   {
       printf("Invalid number of arguments \n");
       return -1;
   }
    
   Ret = mkdir(argv[1], 0777);
  
   if(Ret == 0)
   {
      printf("Directory created successfully \n");
   }
   else
   {
      printf("Unable to create Directory \n");
   }
  
  return 0; 
}
