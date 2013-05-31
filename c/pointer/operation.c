#include <stdio.h>
//指针运算的区别
void main(){
	int a[]={1,2,3};
	int * p1,* p2;
	p1=p2=a;
	printf("*p1++=%d\n",*p1++);
	printf("*++p2=%d\n",*++p2);
}
