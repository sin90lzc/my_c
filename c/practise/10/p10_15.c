#include <stdio.h>
#include <stdlib.h>

static int data[][6]={{1,76,89,79,83,64},{2,86,85,90,94,95},{3,56,61,57,80,83},{4,80,85,99,97,93}};

int average(int n){
	int (*p)[6]=data;
	int i=0;
	int sum=0;
	for(;i<=3;i++){
		sum+=*(*(p+i)+n);
	}
	int result=sum/4;
	return result;
}

void printNoPass(){
	int (*p)[6]=data;	
	while(p<data+4){
		int i=1;
		int count=0;
		for(;i<6;i++){
			count=*(*p+i)<60?++count:count;
		}
		i=0;
		int sum=0;
		//printf("count:%d",count);
		if(count>=2){
			for(;i<6;i++){
				sum+=*(*p+i);
				printf("%5d",*(*p+i));
			}
			sum-=**p;
			printf("%5d\n",sum/5);
		}
		p++;
	}
}


void main(){
	printf("average:%d\n",average(2));
	printf("no pass 2:\n");
	printNoPass();
}
