/* Write a program which creates  processes.
Process 1 count number of capital charaecters from demo.txt.
Process 2 count number of capital charaecters from hello.txt.
Both the processes writes its count in count.txt file */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char Buffer[512];
    int iCnt1 = 0,i = 0;
    int iCnt2 = 0;
    int iRet1 = 0;
    int iRet2 = 0;
    int pid1 = 0;
    int pid2 = 0;
    int fd1 = 0;
    int fd2 = 0;
    int fd = 0;
    
    pid1 = fork();
   
    if(pid1 == 0)
    {
       printf("Inside child process 1\n");
     
       fd1 = open("demo.txt",O_RDONLY);

       while((iRet1 = read(fd1,Buffer,sizeof(Buffer))) != 0)
       {
          for(i = 0; i < iRet1 ; i++)
          {
             if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
             {
                iCnt1++;
             }
          }
       }

       printf("Number of capital characters are : %d\n",iCnt1);

       close(fd1);
     }
     
    pid2 = fork();
   
    if(pid2 == 0)
    {
       printf("Inside child process 2\n");
     
       fd2 = open("hello.txt",O_RDONLY);

       while((iRet2 = read(fd2,Buffer,sizeof(Buffer))) != 0)
       {
          for(i = 0; i < iRet2 ; i++)
          {
             if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
             {
                iCnt2++;
             }
          }
       }

       printf("Number of capital characters are : %d\n",iCnt2);

       close(fd2);
     }
     
     fd = open("count.txt", O_RDWR);
     
     write(fd , iCnt1, sizeof(iCnt1));
     write(fd , iCnt2, sizeof(iCnt2));

     return 0;
}
