/* 5. Write a program which accepts file name and position from user & read 20 bytes from that position. */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int fd        = 0;
  int iRet      = 0;
  int iPosition = 0;
  char Buffer[20] = {'\0'};
 
  printf("Usage : Executable_Name File_Name Position\n");
  
  if(argc != 3)
  {
      printf("Invalid number of arguments \n");
      return -1;
  }
  
  fd = open(argv[1], O_RDONLY);
  
  if(fd == -1)
  {
      printf("Unable to open file\n");
  }
  else
  {
     printf("File is opened successfully with fd : %d\n", fd);
  }
  
  iPosition = atoi(argv[2]);
  
  lseek(fd,iPosition,SEEK_SET);
  
  iRet = read(fd,Buffer,20);
  
  write(1,Buffer,iRet);
  
  printf("\n");
  
  close(fd);

  return 0; 
}
