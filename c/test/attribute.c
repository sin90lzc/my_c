#include <stdio.h>
#ifndef __GNUC__
#define __attribute(x)
#endif
void iprintf(const char * str,...){
	printf(str,...);
}
//这里使用了format属性和weak属性
void iprintf(const char * str,...)__attribute__((format(printf,1,2),weak));


int main(int argc,char ** argv){
	iprintf("abc%s%d\n",11,"abc");
}
