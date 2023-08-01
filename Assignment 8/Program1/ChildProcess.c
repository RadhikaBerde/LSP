#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{  
  printf("Inside Child Process -  PID of Paraent process is %d\n", getppid());
  return 0;
}
