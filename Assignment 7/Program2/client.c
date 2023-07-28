/* Write a program which is used to create shared library and that library should be loaded at runtime by the other program.
   The library should contain function which should accept 2 file names from user and it will compare the contents of that 2 files. */

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{ 
   void *ptr = NULL;
   int (*fptr)();
   int iRet = 0;
   char File1[100];
   char File2[100];
   
   printf("Enter Filename1 : ");
   scanf("%s", File1);
   
   printf("Enter Filename2 : ");
   scanf("%s", File2);
   
   ptr = dlopen("./library.so", RTLD_LAZY);
   
   if(ptr == NULL)
   {
      printf("Unable to load library\n");
      return -1;
   }
   
   fptr = dlsym(ptr, "CompareFiles");
   
   if(fptr == NULL)
   {
      printf("Unable to load address of function\n");
      return -1;
   }
   
   iRet = fptr(File1, File2);
   
   if(iRet == 0)
   {
      printf("Both files are identical\n");
   }
   else
   {
      printf("Both files are different\n");
   }
   
   return 0;
}

/*Steps

gcc -c -fPIC sharedfile.c
gcc -shared -o library.so sharedfile.o
gcc -rdynamic -o Myexe client.c
./Myexe

*/
