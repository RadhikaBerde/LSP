/* Write a program which is used to create share library and that library should be loaded at run time by the program.
The library should contain functions to perform arithmetic operations like addition, substraction, multiplcation & Division. */

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptradd)(int,int);
    int (*fptrsub)(int,int);
    int (*fptrdivide)(int,int);
    int (*fptrmultiply)(int,int);
    
    int iValue1 = 11;
    int iValue2 = 10;

    ptr = dlopen("./library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptradd    = dlsym(ptr,"Addition");
    fptrsub    = dlsym(ptr,"Substraction");
    fptrdivide = dlsym(ptr,"Multiplication");
    fptrmultiply   = dlsym(ptr,"Division");
    
    if((fptradd == NULL) || (fptrsub == NULL) || (fptrdivide == NULL) || (fptrmultiply == NULL))
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptradd(iValue1,iValue2);
    fptrsub(iValue1,iValue2);
    fptrdivide(iValue1,iValue2);
    fptrmultiply(iValue1,iValue2);
    
    return 0;
}

//Steps :
//gcc -c -fPIC sharedfile.c
//gcc -shared -o library.so sharedfile.o
//gcc -rdynamic -o Myexe Program1.c
//./Myexe
