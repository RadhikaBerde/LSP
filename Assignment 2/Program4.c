/* 4. Write a program which accepts directory name from user & print all file names & its type from that directory. */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    
    printf("Usage : Executable_Name Directory_Name\n");
    
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
        printf("File Name : %20s   Type : %d   ",entry->d_name, entry->d_type);
        
        if( entry->d_type == DT_REG)
        {
           printf("Its a regular File\n");
        }
        else if( entry->d_type == DT_DIR)
        {
           printf("Its a directory File\n");
        }
        else if( entry->d_type == DT_DIR)
        {
           printf("Its a directory File\n");
        }
        else if( entry->d_type == DT_CHR)
        {
           printf("Its a character Device\n");
        }
        else if( entry->d_type == DT_BLK)
        {
           printf("Its a block device\n");
        }
        else if( entry->d_type == DT_LNK)
        {
           printf("Its a Symbolic link \n");
        }
    }
   
   return 0;
}
