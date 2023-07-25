#include "sharedfile.h"

int Addition(int ino1, int ino2)
{
    int iAns = 0;
    iAns = 10 + 11;
    printf("Addition is : %d\n", iAns);
}

int Substraction(int no1, int no2)
{
    int iAns = 0;
    iAns = 11 - 10;
    printf("Substraction is : %d\n", iAns);
}

int Multiplication(int no1, int no2)
{
    int iAns = 0;
    iAns = no1 * no2;
    printf("Multiplication is : %d\n", iAns);
}

int Division(int no1, int no2)
{
    int iAns = 0;
    iAns = no1 / no2;
    printf("Division is : %d\n", iAns);
}
