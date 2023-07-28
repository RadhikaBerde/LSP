/* Write a program which is used to create share library and that library should be loaded at run time by the program.
The library should contain functions to perform arithmetic operations like addition, substraction, multiplcation & Division.
*/

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
    
    int iValue1 = 0;
    int iValue2 = 0;
    int iRet_add = 0;
    int iRet_sub = 0;
    int iRet_Divide = 0;
    int iRet_Multiply = 0;
    
    printf("Enter iNo1 : ");
    scanf("%d", &iValue1);
    
    printf("Enter iNo2 : ");
    scanf("%d", &iValue2);
    
    ptr = dlopen("./library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptradd        = dlsym(ptr,"Addition");
    fptrsub        = dlsym(ptr,"Substraction");
    fptrdivide     = dlsym(ptr,"Multiplication");
    fptrmultiply   = dlsym(ptr,"Division");
    
    if((fptradd == NULL) || (fptrsub == NULL) || (fptrdivide == NULL) || (fptrmultiply == NULL))
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    iRet_add      = fptradd(iValue1,iValue2);
    iRet_sub      = fptrsub(iValue1,iValue2);
    iRet_Divide   = fptrdivide(iValue1,iValue2);
    iRet_Multiply = fptrmultiply(iValue1,iValue2);
    
    printf("Addition is : %d\n", iRet_add);
    printf("Substraction is : %d\n", iRet_sub);
    printf("Division is : %d\n", iRet_Divide);
    printf("Multiplication is : %d\n", iRet_Multiply);
    
    return 0;
}

//Steps :
//gcc -c -fPIC sharedfile.c
//gcc -shared -o library.so sharedfile.o
//gcc -rdynamic -o Myexe Program1.c
//./Myexe
