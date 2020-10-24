# 1 "./Src/app_main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "./Src/app_main.c"
# 1 "./Inc/app_main.h" 1



extern void vidFunc(short int *u16FuncArgPtr);
# 2 "./Src/app_main.c" 2

char u8InitGLobalVar = 2;
static long int u32NonInitStaticGlobalVar;
const short int u16ConstGlobalVar = 3;


const long int sprintARR[20] __attribute__((section("sprint"))) ={0};

void main(void)
{
 short int u16LocVar = 4;
 static char u8InitStaticLocVar = 5;
 if(u16ConstGlobalVar == 3)
 {

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
