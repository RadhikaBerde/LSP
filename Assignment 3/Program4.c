/* Write a program which accepts two directory names from user and delete all empty files from that directory*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    printf("Usage : Executable_Name Directory_Name\n");
    
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char path[1024] = {'\0'};
    int fd = 0;
    
    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    
    if(dp == NULL)
    {
       printf("Unable to open directory \n");
       return -1;
    }
   
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(path,"%s/%s",argv[1],entry->d_name);
        fd = open(path, O_RDONLY);
                
        fstat(fd,&sobj);
        if(sobj.st_size == 0 )
        {
            remove(path);
            printf("File is succesfully deleted\n");
        }
    }
    
   return 0;
}
