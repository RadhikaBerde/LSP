#include "sharedfile_checkprime.h"

int CheckPrime(int iNo)
{  
   int iCnt = 0;
   int iFlag = 1;
   
   for(iCnt = 2; iCnt< iNo; iCnt++)
   {
      if(iNo%iCnt == 0)
      {
         iFlag = 0;
         break;
      }
   }
   
  return iFlag;
   
}
