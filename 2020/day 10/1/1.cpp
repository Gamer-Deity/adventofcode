#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

#define  MEM_ERROR -1
#define  COLLISION -2
#define  OK         0

#define INP_LENGTH 31


typedef struct __BTCell2 {
   int iVal;
   struct __BTCell2 *pstBelow;
   struct __BTCell2 *pstAbove;
} BTCell2;


BTCell2 *gpstRoot2 = NULL;


//////////////////////////////////////////////
//////////////////////////////////////////////
int iBT_Insert (int iVal, BTCell2 **ppstCell)
{

   if ((*ppstCell) == NULL) {
      
      *ppstCell = (BTCell2*)malloc (sizeof (BTCell2));
      
      //if (iLastUsed >= MAX_RECS) return MEM_ERROR;
      //*ppstCell = &gvstTree[iLastUsed++];
      
      
      if (*ppstCell == NULL) return MEM_ERROR;
      
      memset (*ppstCell, 0, sizeof (BTCell2));
      
      (*ppstCell)->iVal = iVal;
   
   } else {
      
      if ((*ppstCell)->iVal == iVal)
         return COLLISION;
   
      if ((*ppstCell)->iVal < iVal)
         iBT_Insert (iVal, &(*ppstCell)->pstAbove);
      
      if ((*ppstCell)->iVal > iVal)
         iBT_Insert (iVal, &(*ppstCell)->pstBelow);
     
   }
   
   return OK;
}

//////////////////////////////////////////////
//////////////////////////////////////////////
void BT_Destroy2 (BTCell2 **ppstCell)
{
   if (*ppstCell != NULL) {
   
      BT_Destroy2 (&(*ppstCell)->pstBelow);
      
      BT_Destroy2 (&(*ppstCell)->pstAbove);
      
      free (*ppstCell);
      *ppstCell = NULL;
   
   }
}


//////////////////////////////////////////////
//////////////////////////////////////////////
void iBT_Print (BTCell2 **ppstCell)
{
   if (*ppstCell != NULL) {
   	
      	iBT_Print (&(*ppstCell)->pstBelow);
      
      	printf ("\r\n[%d]", (*ppstCell)->iVal);

      	iBT_Print (&(*ppstCell)->pstAbove); 
   }
}


int main (void)
{
	int iInput[INP_LENGTH] = {
		28,
		33,
		18,
		42,
		31,
		14,
		46,
		20,
		48,
		47,
		24,
		23,
		49,
		45,
		19,
		38,
		39,
		11,
		1 ,
		32,
		25,
		35,
		8 ,
		17,
		7 ,
		9 ,
		4 ,
		2 ,
		34,
		10,
		3
	};
	int i, x;
	
	for(i = 0; i < sizeof(iInput)/sizeof(int); i++)
	{
		//x = rand() % INP_LENGTH;
		iBT_Insert(iInput[i], &gpstRoot2);
		//iBT_Insert(x, &gpstRoot2);
		//printf("%d\n", x);
	}
		
	iBT_Print(&gpstRoot2);
	
	BT_Destroy2(&gpstRoot2);
}
