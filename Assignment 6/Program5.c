/* 5. Write a program which accepts file name and offset from user & remove all the data from that offset. */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc , char *argv[]) 
{   
    int fd = 0;
    int iRet = 0;
    int iRet1 = 0;
    int offset = 0;
    char buffer[256];
    
    printf("Usage : Executable_Name File_Name Offset \n");
    
    if (argc != 3) 
    {
        printf("Invalid number of arguments\n");
        return 1;
    }
    
    offset = atoi(argv[2]);
    
    fd = open(argv[1], O_RDWR);
    if (fd == -1) 
    {
        printf("Unable to open file\n");
        return -1;
    }
    
    printf("File opened successfully with fd : %d \n", fd);
    
    iRet = lseek(fd, offset, SEEK_SET);
    
    if (iRet == -1) 
    {
        printf("Unable to set file offset\n");
        return -1;
    }

    memset(buffer, 0, sizeof(buffer));  // Fill buffer with null bytes

    iRet1 = write(fd, buffer, sizeof(buffer));
    
    if (iRet1 == -1) 
    {
        perror("Unable to remove data from file\n");
        return -1;
    }

    printf("Data removed successfully.\n");

    close(fd);
    
    return 0;
}
