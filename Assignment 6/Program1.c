/* 1. Write a program which accepts file name which contains data of all files. We have to print all file names whose size is greater than 10 bytes. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    int fd = 0;
    int iRet = 0;
    struct FileInfo fobj;
    
    printf("Usage : Executable_Name File_Name\n");
    
    if(argc != 2)
    {
       printf("Invalid number of arguments\n");
       return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
       printf("Unable to open file\n");
       return -1;
    }
    
    printf("File opened sucessfully with fd : %d\n", fd);
    
    while((iRet = read(fd,&fobj,sizeof(fobj))) > 0 )
    {   
         if(fobj.FileSize > 10)
         {
             printf("File Name : %s\n ",fobj.FileName);
         }
    }

    close(fd);
    
    return 0;
}
