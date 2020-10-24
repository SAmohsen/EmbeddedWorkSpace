#include "app_main.h"

char u8InitGLobalVar = 2;
static long int u32NonInitStaticGlobalVar; 
const short int u16ConstGlobalVar = 3;

//#pragma __attribute__((section("sprint")))
const long int sprintARR[20] __attribute__((section("sprint"))) ={0};

void main(void)
{
	short int u16LocVar = 4;
	static char u8InitStaticLocVar = 5;
	if(u16ConstGlobalVar == 3)
	{
		/*perform Some lofic To disable Compiler Optmization*/
		u32NonInitStaticGlobalVar = sprintARR[0];
		vidFunc(&u16LocVar);
	}
	else
	{
		u32NonInitStaticGlobalVar = 7;
	}
	while(1)
	{
	
	}
}
