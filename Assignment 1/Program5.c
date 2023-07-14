/* 5 Write a program which accepts file name and number of bytes from user and read that number of bytes from file. */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc , char * argv[])
{
  int fd   = 0;
  int iRet = 0;
  int Size = 0;
  char * Buffer = NULL;
  
  printf("Usage : Name_of_Executable Name_of_file Number_of_bytes \n");
  
  if(argc != 3)
  {
     printf("Invalid number of arguments\n");
     return -1;
  }
  
  fd = open(argv[1], O_RDONLY);
  
  if(fd == -1)
  {
    printf("Unable to open file \n");
    return -1;
  }
  else
  {
    printf("File opened successfully with fd : %d \n", fd);
  }
    
  Size = atoi(argv[2]);
  
  Buffer = (char*) malloc(Size);
  
  iRet = read(fd,Buffer,Size);
  
  if(iRet == 0)
  {
    printf("Unable to read the data from file\n");
  }
  else
  {
    printf("Data from file is : %s\n", Buffer);
  }
  
  return 0;
}
