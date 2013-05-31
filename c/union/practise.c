#include <stdio.h>
void main(int argc,char **argv){
	union uv{
		int a;
		char b;	
	};
	union uv v;
	v.a=8;
	union uv * p=&v;
	printf("%d\n",p->a);
}
