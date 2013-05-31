#include <stdio.h>
/*

*/
void main(int argc,char **argv){
	int stringToInt(char *);
	void sortStr(char **,int);
	char ** p;
	int n=argc-1;
	p=argv+1;
	int i=n;
	sortStr(p,n);
	i=n;
	p=argv+1;
	while(i--){
		printf("%s,",*p++);
	}	
	printf("\n");	
}

void sortStr(char ** strs,int n){
	int i=0,j=0;
	int min;
	char * temp;
	for(;i<n-1;i++){
		min=i;
	//	mstr=*(strs+i);
		for(j=i;j<n-1;j++){
			if(strcmp(*(strs+j),*(strs+j+1))>0){
				min=j+1;
				//mstr=*(str+j+1);
			}
		}
		temp=*(strs+i);
		*(strs+i)=*(strs+min);	
		*(strs+min)=temp;
	}
}

int stringToInt(char *str){
	int result=0;
	while(*str!='\0'){
		result=result*10+(*str++-'0');
	}
	return result;
}
