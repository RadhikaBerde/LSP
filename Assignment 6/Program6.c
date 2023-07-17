/* 6. Write a program which accepts directory name from user & create hole in file if size is less than 1KB & if it is greater than 1KB then truncate the remaining data. */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char filepath[300] = {'\0'};
    int iRet = 0;
    int fd = 0;
    char hole = '\0';
    char Buffer[1000] = {'\0'};
    
    printf("Usage : Executable_Name Directory_Name \n");
    
    if(argc != 2)
    {
       printf("Invalid number of arguments\n");
       return -1;
    }
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
       printf("Unable to open directory\n");
       return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
       sprintf(filepath,"%s/%s",argv[1],entry->d_name);
       
       stat(filepath,&sobj);
       if(S_ISREG(sobj.st_mode))
       {
           fd = open(filepath, O_RDWR);
           if(fd == -1)
           {
               printf("Unable to open file\n");
               return -1;
           } 
           
           if(sobj.st_size < 1024)
           {  
              printf("File opened sucessfully with fd : %d \n", fd);
              printf("%s : ",entry->d_name);
              printf("File Size is less than 1024\n");  
              
              lseek(fd,0,SEEK_END);
              write(fd,&hole,sizeof(hole));
              printf("Hole is created in the file : %s\n", entry->d_name);
           }
           else
           {
             printf("%s : ",entry->d_name);
             printf("File Size is greater than 1KB\n"); 
             
             iRet = truncate(filepath,1024);   
             if(iRet == -1)
             {
                printf("File is not truncate\n");
             }
           }
           
           close(fd);
       }
    }
    
    closedir(dp);
    
    return 0;
}
