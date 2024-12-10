#include <stdio.h>
#include <string.h>
#include <memory.h>

#define  MEM_ERROR -1
#define  COLLISION -2
#define  OK         0

#define INP_LENGTH 107


typedef struct __BTCell2 {
   int iVal;
   struct __BTCell2 *pstBelow;
   struct __BTCell2 *pstAbove;
} BTCell2;


BTCell2 *gpstRoot2 = NULL;

int iCount1 = 0, iCount3 = 1, lastNum = 0;

//////////////////////////////////////////////
//////////////////////////////////////////////
int iBT_Insert (int iVal, BTCell2 **ppstCell)
{

   if ((*ppstCell) == NULL) {
      
      *ppstCell = malloc (sizeof (BTCell2));

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
      	
      	if(lastNum != (*ppstCell)->iVal)
      	{
      		switch((*ppstCell)->iVal - lastNum)
      		{
      			case 1: 
				  	iCount1++;
      				break;
      			case 3:
      				iCount3++;
      				break;
			}
		}
		
		lastNum  = (*ppstCell)->iVal;

      	iBT_Print (&(*ppstCell)->pstAbove); 
   }
}


int main (void)
{
	int iInput[INP_LENGTH] = {
		83,
		69,
		170,
		56,
		43,
		111,
		117,
		135,
		136,
		176,
		154,
		65,
		107,
		169,
		141,
		151,
		158,
		134,
		108,
		143,
		114,
		104,
		49,
		55,
		72,
		73,
		144,
		13,
		35,
		152,
		98,
		133,
		31,
		44,
		150,
		70,
		118,
		64,
		39,
		137,
		142,
		28,
		130,
		167,
		101,
		100,
		120,
		79,
		153,
		157,
		89,
		163,
		177,
		3,
		1,
		38,
		16,
		128,
		18,
		62,
		76,
		78,
		17,
		63,
		160,
		59,
		175,
		168,
		54,
		34,
		22,
		174,
		53,
		25,
		129,
		90,
		42,
		119,
		92,
		173,
		4,
		166,
		19,
		2,
		121,
		7,
		71,
		99,
		66,
		46,
		124,
		86,
		127,
		159,
		12,
		91,
		140,
		52,
		80,
		45,
		33,
		9,
		8,
		77,
		147,
		32,
		95
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
	
	printf("\n\n1: %d\n3: %d\nProduct: %d\n", iCount1, iCount3, iCount1 * iCount3);
}
