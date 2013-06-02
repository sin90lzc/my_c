#include<stdio.h>

int main(int argc,char ** argv){
	int (*p)[2];
	int a[][2]={{1,2},{3,4}};
	p=&a[0];
	//printf("%d\n",**(p+2));
	printf("%d\n",**a);
	//p=a;	
	printf("%d\n",*(*p+1));
	//	
	
}
