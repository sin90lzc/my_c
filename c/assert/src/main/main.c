#include <stdio.h>
//断言控制开关
//#define ENABLE_ASSERT_TEST
//#undef ENABLE_ASSERT_TEST
#include "assert.h"

int main(int argc,char ** argv){
	int g=1;
	int f=0;
	ASSERT(g);
	ASSERT(f);
	return 0;
}
