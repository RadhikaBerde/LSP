/* Write a program which accepts directory name from user and copy first 10 bytes of all regular files into newly created file
named as Demo.txt */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int fddest = 0;
    int iRet = 0;
    char name[1024] = {'\0'};
    char Buffer[10] = {'\0'};
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    
    printf("Usage : Executable_Name Directory_Name File_Name \n");
    
    if(argc != 3)
    {
       printf("Invalid number of arguments \n");
       return -1;
    }
    
    fddest = creat(argv[2],0777);
    
    dp = opendir(argv[1]);
    
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        
        fd = open(name,O_RDONLY);
        
        if( entry->d_type == DT_REG)
        {           
           fd = open(name,O_RDONLY);
           iRet = read(fd,Buffer,10);
           write(fddest,Buffer,iRet);      
         }        
    }
    
    printf("Data is copied succesfully\n");
    
    closedir(dp);
    
    return 0;
}
