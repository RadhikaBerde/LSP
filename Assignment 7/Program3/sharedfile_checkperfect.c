#include "sharedfile_checkperfect.h"

int CheckPerfect(int iNo)
{
   int iCnt = 0;
   int iSum = 0;
   int iFlag = 0;
   
   for(iCnt = 1; iCnt < iNo ; iCnt++)
   {
     if(iNo%iCnt == 0)
     {
        iSum = iSum + iCnt;
     }
   }
   
   if(iNo == iSum)
   {
      iFlag = 1;
   }

   return iFlag;
}
