/**
 *
 * 该程序用于测试逗号表达式的执行顺序。
 */
#include<stdio.h>

#define ORDERRESULT(a,b) "逗号表达式为从"#a"至"#b"的执行顺序!\n"
#define TRESULT(a) "逗号表达式的值为逗号"#a"侧表达式的值!\n"
int main(int argc,char ** argv){
	int i=1;
	int k=0;
	int r=(100,(k=i,++i));
	
	//printf("k:%d\n",k);

	if(k==1){
		printf(ORDERRESULT(左,右));
	}else if(k==2){
		printf(ORDERRESULT(右,左));
	}
	//printf("j:%d\n",j);	
	
	if(r==100){
		printf(TRESULT(左));
	}else{
		printf(TRESULT(右));

	}
	
	return 0;
}
