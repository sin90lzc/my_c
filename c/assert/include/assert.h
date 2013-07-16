//自定义断言

#include <stdlib.h>
#include <stdio.h>


//ENABLE_ASSERT_TEST为断言的开关
//#undef ENABLE_ASSERT_TEST

/**
 *
 * 断言的判断出错时的输出方法
 *
 */
#ifdef ENABLE_ASSERT_TEST
void assert_msg(__const char * file,int line,__const char * func){
	printf("assert error: file:%s,line:%u,function:%s\n",file,line,func);
	abort();
}
#endif


#ifdef ENABLE_ASSERT_TEST
#define ASSERT(condition) \
	do{\
		if(condition) \
			NULL; \
		else \
			assert_msg(__FILE__,__LINE__,__func__); \
	}while(0)
#else
#define ASSERT(condition) \
	NULL
#endif
