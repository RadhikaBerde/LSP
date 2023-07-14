/* 5. Write a program which accepts directory name from user & print name of such a file having largest size. */

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
    int fd = 0;
    int File_Size = 0;
    char str1[100] = "/home/dell/Desktop/Assignments/Assignment_No_2/Radhika_Folder/";
    char str2[100] = {'\0'};
    char File_name[20] = {'\0'};
    
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
        strcpy(str1,"/home/dell/Desktop/Assignments/Assignment_No_2/");
        strcat(str1,argv[1]);
        strcat(str1,"/");
        strcat(str1,entry->d_name);
        strcat(str2,str1);
        
        printf("%s\n", str2);
        
        fd = open(str2, O_RDONLY);
        
        fstat(fd,&sobj);
        if(sobj.st_size > File_Size)
        {
            File_Size = sobj.st_size;
            strcpy(File_name, entry->d_name);
        }
        
        strcpy(str1, "");
        strcpy(str2, "");
    }
   
   printf("Name of the file having largest size is : %s\n", File_name);
   
   return 0;
}
