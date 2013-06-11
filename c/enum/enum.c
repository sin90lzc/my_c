/**
 *
 * enum类型的使用练习
 */

#include <stdio.h>

int main(int argc,char ** argv){
	enum weekday{sun,mon,tue,wed,thr,fri,sat};
	printf("%d,%d,%d,%d,%d,%d,%d\n",sun,mon,tue,wed,thr,fri,sat);

	typedef enum weekday WEAKDAY;
	
	WEAKDAY birth=sat;

	printf("mybirth:%d\n",birth);

	WEAKDAY * pw=NULL;

	//pw=&tue;//这样写是错误的，因为tue是常量，不是变量

	return 0;
}
