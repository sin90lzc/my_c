#include <stdio.h>

int addNum(int a,int b){
	int c=0;
	c=a+b;
	return c;
}

int add(...,int a,int b){
}

int main(int argc,char ** argv){
	addNum(1,2);
}
