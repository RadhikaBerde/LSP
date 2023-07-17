/* 1. Write a program which accepts two file name from user & copy the contents of existing file to new created file */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int Ret = 0;

    char Buffer[BLOCKSIZE] = {'\0'};

    printf("Usage : Executable_Name Existing_File_Name New_File_Name\n");
    
    if(argc != 3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fdSource = open(argv[1],O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("Unable to create destination file\n");
        close(fdSource);
        return -1;
    }

    while((Ret = read(fdSource,Buffer,sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,Ret);
        memset(Buffer,0,sizeof(Buffer));
    }

    close(fdSource);
    close(fdDest);

    return 0;
}
