/* Write a program which write structure in file. Structure should contain information of Student. */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};
   
int main(int argc, char *argv[])
{ 
    struct Student sobj;
    int fd = 0;
   
    printf("Usage : Executable_Name New_File_Name\n");
    
    if(argc != 2)
    {
       printf("Invalid number of parameters \n");
       return -1;
    }
    
    sobj.Rollno = 1;
    sobj.Marks = 75.50f;
    sobj.Age = 25;
    strcpy(sobj.Sname,"Radhika");
    
    fd = creat(argv[1],0777);
    
    write(fd,&sobj,sizeof(sobj));

    return 0;
}
