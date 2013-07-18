#include <stdio.h>
#define DO_SOMETHING(hello,world) do{ \
	printf(hello);  \
	printf(world);}while(0)


int main(int argc,char ** argv){
	DO_SOMETHING("hello"," world\n");
	return 0;
}
