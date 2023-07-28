
#include<stdio.h>
#include<dlfcn.h>
#include "sharedfile_factorial.h"

int calculate_factorial(int iNo)
{
  void *ptr = NULL;
  int (*fptr)(int) = NULL;
  int iRet = 0;
  
  ptr = dlopen("./libfactorial.so", RTLD_LAZY);
  
  if(ptr == NULL)
  {
     printf("Unable to load library\n");
     return -1;
  }
  
  fptr = dlsym(ptr,"Factorial");
  
  if(fptr == NULL)
  {
     printf("Unable to load Address of Factorial function\n");
     return -1;
  }
  
  iRet = fptr(iNo);
  
  return iRet;

}
