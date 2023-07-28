#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include "sharedfile.h"

int CompareFiles(char *file1, char *file2)
{
    int fd1 = 0;
    int fd2 = 0;
    int ret = 0;
    int iCnt = 0;
    int Flag = 1;
    char Buffer1[1024];
    char Buffer2[1024];
    struct stat obj1, obj2;
   
    fd1 = open(file1,O_RDONLY);
    fd2 = open(file2,O_RDONLY);
    
    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size) /*Files are different as sizes are different */
    {
        return -1;
    }

    while((ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        iCnt++;
        ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,ret) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        Flag = 0;
    }

    close(fd1);
    close(fd2);

    return Flag;
}
