/* Write a program which is used to create 2 shared libraries and that library should be loaded at run time by the other program.
First library should contain function to check whether the input number is prime or not.
Second library should contain function to check whether the input number is perfect or not.
*/

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
   void *ptr_prime   = NULL;
   void *ptr_perfect = NULL;
   int (*fptr_prime)(int) = NULL;
   int (*fptr_perfect)(int) = NULL;
   int iNo = 0;
   int iRet_prime = 0;
   int iRet_perfect = 0;
   
   printf("Enter iNo : ");
   scanf("%d", &iNo);
   
   ptr_prime = dlopen("./libprime.so", RTLD_LAZY);
   
   if(ptr_prime == NULL)
   {
      printf("Unable to load libprime\n");
      return -1;
   }
   
   ptr_perfect = dlopen("./libperfect.so", RTLD_LAZY);
   
   if(ptr_perfect == NULL)
   {
      printf("Unable to load libperfect\n");
      return -1;
   }
   
   fptr_prime = dlsym(ptr_prime,"CheckPrime");
   if(fptr_prime == NULL)
   {
      printf("Unable to load the address of CheckPrime function \n");
      return -1;
   }
   
   fptr_perfect = dlsym(ptr_perfect,"CheckPerfect");
   if(fptr_perfect == NULL)
   {
      printf("Unable to load the address of CheckPerfect function \n");
      return -1;
   }
   
   iRet_prime   = fptr_prime(iNo);
   iRet_perfect = fptr_perfect(iNo);
   
   if (iRet_prime == 0)
   {
   	printf("Number %d is not a prime number\n", iNo);
   }
   else
   {
      printf("Number %d is a prime number\n", iNo);
   }
   
   if (iRet_perfect == 0)
   {
   	printf("Number %d is not a perfect number\n", iNo);
   }
   else
   {
      printf("Number %d is a perfect number\n", iNo);
   }
   
   return 0;
}

/*Steps

gcc -c -fPIC sharedfile_checkprime.c
gcc -c -fPIC sharedfile_checkperfect.c
gcc -shared -o libprime.so sharedfile_checkprime.o
gcc -shared -o libperfect.so sharedfile_checkperfect.o
gcc -rdynamic -o Myexe client.c
./Myexe

*/
