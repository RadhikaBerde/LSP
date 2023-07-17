/* 2. Write a program which accepts directory name & file name from user and chcek whether that file is present in that directory or not ?*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{ 
   DIR * dp = NULL;
   struct dirent * entry = NULL;
   int Flag = 0;
   int Ret = 0;
   
   printf("Used to check if file is present in the directory\n");
   printf("Usage : Directory_Name File_Name\n");
   
   if(argc != 3)
   {
      printf("Invalid number of arguments\n");
      return -1;
   }
   
   dp = opendir(argv[1]);
   
   if(dp == NULL)
   {
     printf("Unable to open directory\n");
   }
   else
   {
     printf("Directory opened sucessfully\n");
   }
     
   while((entry = readdir(dp)) != NULL)
   {      
      Ret = strcmp(argv[2],entry->d_name);
      if(Ret == 0)
      {
         Flag = 1;
         break;
      }
   }
   
   if(Flag == 1)
   {
     printf("File is present in the directory\n");
   }
   else
   {
     printf("File is not present in the direcoty\n");
   }
   
   return 0;
}
