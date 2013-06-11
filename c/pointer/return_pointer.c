/**
 *
 * 练习使用返回指向数组指针的函数
 */
#include <stdio.h>

int main(){
	int (*getArray())[4];
	int (*a)[4]=getArray();
	//int a[4]=getArray();	
	//int i=0;
	printf("%d,%d,%d,%d\n",**a,*(*a+1),*(*a+2),*(*a+3));
	return 0;
}

//返回一个指向数组的指针
int (*getArray())[4]{
	int a[][4]={{0,1,2,3}};
	int (*p)[4]=a;
	return p;
}
