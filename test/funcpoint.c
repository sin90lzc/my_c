#include<stdio.h>

int main(int argc,char ** argv){
	extern int getNum(int (*)(int,int),int,int);
	extern int getMax(int,int);
	extern int getMin(int,int);
	//printf("%d\n",argc);	
	if(argc!=2){
		fprintf(stderr,"error:need a number parameter!");
		return 1;
	}
	
	char * p=*(argv+1);
	int result=0;

	printf("%s\n",p);
	
	if(strcmp(p,"0")){
		result=getNum(getMax,3,5);
	}else{
		result=getNum(getMin,3,5);
	}
	printf("result=%d\n",result);
		
}

int getNum(int (*p)(int,int),int a,int b){
	return (*p)(a,b);
}

int getMax(int a,int b){
	return a>b?a:b;
}

int getMin(int a,int b){
	return a>b?b:a;
}
