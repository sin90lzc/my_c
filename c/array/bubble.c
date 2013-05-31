#include <stdio.h>

//冒泡算法
void main(){
	int i=0;
	int a[5];
	printf("please enter 5 number:\n");
	for(;i<5;i++){
		scanf("%d",&a[i]);
	}
	
	printf("you has entered:\n");
	for(i=0;i<5;i++){
		printf("%5d",a[i]);
	}
	printf("\n");
	int j=0;
	//每次循环把最大的值置于数组末,因此要进行n-1次循环	
	for(i=0;i<4;i++){
		//每次外循环能定下最大值，因此只需4-i次循环
		for(j=0;j<4-i;j++){
			if(a[j]>a[j+1]){
				int b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;	
			}
		}
	}
	printf("the result:\n");
	for(i=0;i<5;i++){
		printf("%5d",a[i]);
	}
	printf("\n");
}
