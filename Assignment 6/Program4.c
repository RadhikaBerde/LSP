/* 4. Write a program which accepts directory name from user & delete all such files whose size is greater than 100 bytes. */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[257];
    struct stat sobj;
    
    printf("Usage : Executable_Name Directory_Name\n");
    
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
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(sobj.st_size > 100)
        {
            remove(name);
        }
    }

    closedir(dp);
    
    return 0;
}
