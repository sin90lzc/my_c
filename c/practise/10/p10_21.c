#include <stdio.h>
/*
用指向指针的指针的方法对n个整数排序并输出，要求将排序单独写成一个函数。n个整数在主函数中输入，最后在主函数中输出。
*/
void main(int argc,char * argv[]){
	void printArray(int **p,int n);
	int stringToInt(char *);
	void sort(int **p,int n);
	int n;
//	printf("%d\n",argc);
	if(argc<2){
		printf("请输入要排序数的数量！\n");
		//exit(1);
	}	
//	printf("%s\n",*(argv+1));
	//printf("%d,%d",sizeof(int),sizeof(char));
	n=stringToInt(*(argv+1));
	//printf("%d\n",n);
	int * p[n];
//	int a[n];
	int * temp;
	
	printf("请输入%d个整数用于排序:\n",n);
	int i=0;
	temp=(int *)calloc(sizeof(int),n);
	for(;i<=n-1;i++){
		*(p+i)=temp+i;
	}
	for(i=0;i<=n-1;i++){
		scanf("%d",*(p+i));
	}	
	printArray(p,n);
	sort(p,n);
	printArray(p,n);	
}
void sort(int **p,int n){
	int i,j;
	int * temp;
	int min=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(**(p+j)>**(p+j+1)){
				temp=*(p+j+1);	
				*(p+j+1)=*(p+j);
				*(p+j)=temp;
			}	
		}
	}
}
//打印数组值
void printArray(int **p,int n){
	int i=0;
	for(;i<=n-1;i++){
		printf("%5d",**(p+i));	
	}	
	printf("\n");
}
//
int stringToInt(char *p){
	int result=0;
	while(*p!='\0'){
//		printf("%s\n",p);
		result=result*10+(*p-'0');
	//	printf("%d\n",*p);
		p++;
	}
	return result;
}
