/* 3. Write a program which accepts directory name from user & print all file names from that directory. */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char * argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    
    printf("Usage : Name_of_Executable Name_of_Directory \n");
     
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
   
    printf("All File names in the directory :- \n");
    while((entry = readdir(dp)) != NULL)
    {
        printf("%s \n",entry->d_name);
    }
   
    return 0;
}
