/* 3. Write a program which accepts directory name from user & write information of all regular file in and then read that file. */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[300];
    struct stat sobj;
    struct FileInfo fobj;
    int fd = 0;
    int iRet = 0;

    printf("Usage : Executable_Name Directory_Name\n");
    
    if(argc != 2)
    {
      printf("Invalid Number of arguments\n");
      return -1;
    }
    
    fd = creat("FileCombine.txt",0777);
    if(fd == -1)
    {
       printf("Unable to create file\n");
       return -1;
    }
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    
    printf("Write into FileCombine.txt file\n");
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
            printf("%s\n",entry->d_name);
        }
    }
    
    close(fd);
    
    // Open the output file for reading
    fd = open("FileCombine.txt", O_RDONLY);
    
    printf("Read FileCombine.txt file\n");
    
    while((iRet = read(fd,&fobj,sizeof(fobj))) > 0 )
    {   
         printf("File Name : %s  ",fobj.FileName);
         printf("File Size : %d  \n",fobj.FileSize);
    }
    
    if (iRet == -1)
    {
        printf("Failed to read the output file\n");
    }

    closedir(dp);
    
    return 0;
}
