/* 4. Write a program which accepts directory name from user and combine all contains of file from that directory into one file named as combine. */


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int fd1 = 0;
    int iRet = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char FilePath[300] = {'\0'};
    char Buffer[30] = {'\0'};

    if(argc != 3)
    {
        printf("Invalid arguments\n");
        return -1;
    }

    fd = open(argv[2],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1.;
    }
    
    printf("File opened successfully with fd %d\n", fd);
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
       printf("Unable to open directory\n");
       return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(FilePath,"%s/%s",argv[1],entry->d_name);
        fd1 = open(FilePath,O_RDONLY);
        while ((iRet = read(fd1,Buffer,sizeof(Buffer))) > 0)
        {
            write(fd,Buffer,sizeof(Buffer));
        }
    }
    
    return 0;
}   
