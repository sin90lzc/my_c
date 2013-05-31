#include <stdio.h>
//逗号运算符在所有运算符中级别最低
void main(){
	int a=(3+5,5+7);
	int b;
	b=3+5,5+7;
	printf("a=%d,b=%d\n",a,b);
}
