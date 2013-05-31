#include <stdio.h>

#include <stdlib.h>
int parseInt(char *str){
	char * p=str;
	int result=0;
	while(*p>='0' && *p<='9'){
		//printf("%c",*p);
		result=result*10+(*p++-'0');	
	}
	return result;
}
void main(){
	char * str="dfj129io9df0\0";
	int result[20]={0};
	char * pResult[20]={NULL};
	char ** temp=pResult;
	char * p=str;
	int flag=1;
	while(*p++!='\0'){
		//printf("%c\n",*p);
		if(*p>='0' && *p<='9'){
			if(flag==1){
				//printf("is num:%c\n",*p);
			//	printf("aaaaaaaaaaaa\n");
				*temp=p;
				temp++;
			//	printf("bbbbbbbbbb%c\n",*p);
			}		
			flag=0;
		}else{
			flag=1;
		}	
	}
	char ** pp=pResult;
	int i=0;
	for(;*pp!=NULL;i++){
		//printf("uuuuuuuuuuuuu\n");
		result[i]=parseInt(*pp++);
		//printf("%d\n",result[i]);
	}
	int * ip=result;
	for(i=0;i<20;i++){
		printf("%5d",*ip++);
	}	
	printf("\n");
}
