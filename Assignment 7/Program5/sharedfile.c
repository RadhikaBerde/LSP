#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

void FileInfo(char *FileName)
{
    int fd =0;
    struct stat sobj;
    
    fd = open(FileName, O_RDONLY);
    
    if(fd == -1)
    {
       printf("Unable to open file\n");
    }
    else
    {
       printf("File opened sucessfully with fd : %d\n", fd);
    }
    
    fstat(fd,&sobj);
    
    printf("Information of File :- \n");
    
    printf("ID of device containing file : %ld\n", sobj.st_dev);
    printf("Inode Number : %ld\n", sobj.st_ino);
    printf("Mode of file : %d\n", sobj.st_mode);
    printf("Number of hard links to the file: %ld\n", sobj.st_nlink);
    printf("User ID of the file owner : %d\n", sobj.st_uid);
    printf("Group ID of the file owner : %d\n", sobj.st_gid);
    printf("Device ID if the file is a special device  : %ld\n", sobj.st_rdev);
    printf("Size of the file in bytes : %ld\n", sobj.st_size);
    printf("Block size for file system I/O : %ld\n", sobj.st_blksize);
    printf("Number of 512-byte blocks allocated to the file : %ld\n", sobj.st_blocks);
    printf("Last access time of the file : %ld\n", sobj.st_atime);
    printf("Last modification time of the file : %ld\n", sobj.st_mtime);
    printf("last status change time of the file: %ld\n", sobj.st_ctime);
    
    return;
}
