#include <stdio.h>
#include <stdlib.h>
#include <tim.h>
void main(int argc,char ** argv){
	if(argc<=1){
		printf("please enter a number arg!\n");
		exit(1);
	}
	
	int n=parseInt(*(argv+1));
	int data[n];
	printf("please enter %d numbers:\n",n);	
	int i=0;
	for(;i<n;i++){
		scanf("%d",&data[i]);
	}
	int * p=data;
	for(i=0;i<n/2;i++){
		*(p+i)=*(p+i) ^ *(p+n-1-i);
		*(p+n-1-i)=*(p+i) ^ *(p+n-1-i);	
		*(p+i)=*(p+i) ^ *(p+n-1-i);
	}
	p=data;
	for(i=0;i<n;i++){
		printf("%5d",*(p+i));
	}
	printf("\n");
}
