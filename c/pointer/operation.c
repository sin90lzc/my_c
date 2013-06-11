/**
 *
 * ++运算符在指针运算操作中的优先级。可以看出是右结合性
 */
#include <stdio.h>
//指针运算的区别
int main(){
	int a[]={1,2,3};
	int * p1,* p2;
	p1=p2=a;
	printf("*p1++=%d\n",*p1++);
	printf("*++p2=%d\n",*++p2);
	return 0;
}
