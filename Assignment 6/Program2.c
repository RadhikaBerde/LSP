/* 2. Write a program which creates hole of size 1KB at the end of the file. */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
  int  fd =0;
  int  iRet = 0;
  char hole = '\0';
  char Buffer[1024] = {'\0'};
  
  printf("Usage : Executable_Name File_Name\n");
  
  if(argc != 2)
  {
     printf("Invalid number of arguments\n");
     return -1;
  }
  
  fd = open(argv[1], O_RDWR);
  
  if(fd == -1)
  {
     printf("Unable to open file\n");
     return -1;
  } 
  
  printf("File opened sucessfully with fd : %d \n", fd);
  
  iRet = lseek(fd,0,SEEK_END);
  
  if(iRet == -1)
  {
    printf("Unable to lseek file\n");
    return -1;
  }

  write(fd,&hole,sizeof(hole));
  
  return 0;
  
}
