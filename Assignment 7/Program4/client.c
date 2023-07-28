/*Write a program which creates a shared library which internally loads other shared library.
The inner shared library provides the function to calculate factorial of number.
Also write a program which will load the shared library & call the function. */

#include<stdio.h>
#include "sharedfile_loader.h"

int main()
{
 
 int iNo  = 0;
 int iRet = 0;
 
 printf("Enter Number: ");
 scanf("%d",&iNo);
 
 iRet = calculate_factorial(iNo);
 
 printf("Factorial is %d\n", iRet);
 
 return 0;
}

/*

Steps :

gcc -c -fPIC sharedfile_factorial.c
gcc -c -fPIC sharedfile_loader.c
gcc -shared -o libfactorial.so sharedfile_factorial.c
gcc -shared -o libloader.so sharedfile_loader.c -ldl
gcc -o Myexe client.c -ldl -L. -lloader -lfactorial
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/directory
./Myexe

*/
