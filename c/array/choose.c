#include <stdio.h>
void main(){
	int a[5];
	printf("please enter 5 numbers:\n");
	int i=0;
	for(i=0;i<5;i++){
		scanf("%d",a+i);
	}
	void printResult(int *,int);
	printf("you have entered:\n");
	printResult(a,5);	
	void choose(int *,int n);
	choose(a,5);
	printf("the result is:\n");
	printResult(a,5);
		
}
//选择排序法的实现:对比每个数，找到最小值放到a[0],下一次对比n-1个数，找到最小值放到a[1]
void choose(int a[],int n){
	int i=0,j=0;
	int k;
	for(;i<n-1;i++){
		for(j=i;j<n-1;j++){
			if(*(a+j)>*(a+j+1)){
				k=j+1;			
			}
		}
		int t=*(a+i);
		*(a+i)=*(a+k);
		*(a+k)=t;
	}	
}
void printResult(int a[],int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%5d",*(a+i));
	}
	printf("\n");
}
