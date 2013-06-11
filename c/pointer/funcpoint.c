/**
 *
 * 练习使用函数指针
 *
 */
#include<stdio.h>

/**
 *
 * main接受一个参数，如果参数比0大，则执行getNum(getMax,...)，否则执行getNum(getMin,...)。
 */
int main(int argc,char ** argv){
	extern int getNum(int (*)(int,int),int,int);
	extern int getMax(int,int);
	extern int getMin(int,int);
	extern int strcmp(const char *,const char *);

	//printf("%d\n",argc);	
	
	if(argc!=2){
		fprintf(stderr,"error:need a number parameter!\n");
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
		
	return 0;
}


/**
 *
 * 这是一个应用函数指针作为参数的函数。
 */
int getNum(int (*p)(int,int),int a,int b){
	return (*p)(a,b);
}

/**
 *
 * 可作为getNum函数指针形参的实参
 */
int getMax(int a,int b){
	return a>b?a:b;
}

/**
 *
 * 可作为getNum函数指针形参的实参
 */
int getMin(int a,int b){
	return a>b?b:a;
}
