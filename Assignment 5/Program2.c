/* 2.Write a program which accepts file name from user which contains information of employee, we have to read all contains of that file */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Employee
{
    int EID;
    char Ename[20];
};

int main(int argc, char *argv[])
{
    struct Employee eobj;
    int fd = 0;

    printf("Usage : Executable_Name File_Name\n");
    
    fd = open(argv[1],O_RDONLY);

    read(fd,&eobj,sizeof(eobj));

    printf("Employee ID : %d  \n",eobj.EID);
    printf("Employee Name : %s  \n",eobj.Ename);

    close(fd);

    return 0;
}
