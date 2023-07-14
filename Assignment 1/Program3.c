/*3. Write a program which accepts file name & mode from user and that program checks whether our process can access
that file in accepted mode or not. */

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
   int fd = 0;
   int Mode = 0;
   int Permission;
   
   printf("Usage : Name_of_Executable Name_of_file Mode_of_open \n");
   
   if(argc != 3)
   {
      printf("Inavalid number of arguments \n");
      return -1;
   }
   
   if(strcmp(argv[2] , "Read") == 0)
   {
       if((access(argv[1], R_OK)) == 0)
       {
         printf("Process can access the file in accepted Mode \n");
         return 1;
       }
       else
       {
          printf("Process can't access the file in accepted Mode \n");
          return -1;
       }
   }
   else if(strcmp(argv[2] , "Write") == 0)
   {
       if(access(argv[1], W_OK) == 0)
       {
          printf("Process can access the file in accepted Mode \n");
          return 1;
       }
       else
        {
           printf("Process can't access the file in accepted Mode \n");
           return -1;
       }
   }
   else if(strcmp(argv[2] , "Execute") == 0)
   {
       if(access(argv[1], X_OK) == 0)
       {
          printf("Process can access the file in accepted Mode \n");
          return 1;
       }
       else
        {
          printf("Process can't access the file in accepted Mode \n");
          return -1;
       }
   }
   else
   {
      printf("Entered Invalid Mode\n");
   }
 
   return 0;
}
