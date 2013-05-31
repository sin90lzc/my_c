#include<stdio.h>

int main(int argc,char ** argv){
	int i=1;
	int k=0;
	int j=(k=i,++i);
	
	printf("k:%d\n",k);
	printf("j:%d\n",j);	
	
	
}
