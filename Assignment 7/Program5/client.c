/* Write a program which created static library which accepts filename from userand which displays information of that file.*/

#include<stdio.h>
#include "sharedfile.h"

int main()
{
   char File[200] = {'\0'};
   
   printf("Enter File Name : ");
   scanf("%s", File);
   
   FileInfo(File);
   
   return 0;
}

/* Steps :
gcc -c -fPIC sharedfile.c
gcc -c sharedfile.c -o sharedfile.o
ar rcs sharedfile.a sharedfile.o
gcc -static client.c -o Myexe sharedfile.a
*/
