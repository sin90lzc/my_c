#include <stdio.h>
#include <math.h>

int main(int argc,char ** argv ){
	if(argc!=3){
		fprintf(stderr,"must enter two number parameter!\n");
	}
	char * p1=NULL;
	char * p2=NULL;
	 p1=*(argv+1);
	 p2=*(argv+2);
	extern int strToInt_(const char *);
	printf("p1:%s\n",p1);
	printf("p2:%s\n",p2);
	int x=strToInt(p1);
	int n=strToInt(p2);
	int nq=(x+n)/n;
	printf("x:%d\n",x);
	printf("n:%d\n",n);	
	printf("result:%d\n",nq);
}

int powi(int a,int b){
	int i;
	int result=1;
	if(b==0){
		return result;
	}
	for(i=0;i<b;i++){
		result=result*a;
	}
	return result;
}

int strToInt(const char * str){
	int len=strlen(str);
	int i=1;
	int count=0;
	char * p=NULL;
	p=str;
	for(;i<=len;i++){
		char numc=*(p+i-1);			
		int num=numc-'0';
		count+=num*powi(10,len-i);	
	}
	return count;
}
