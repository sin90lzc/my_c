#include <stdio.h>
#include <stdlib.h>
/*

*/
int strcmp(char * str1,char * str2){

	char * p1=str1,* p2=str2;
	
	do{
		if(*p1!=*p2){
			return *p1-*p2;
		}
		//printf("%c,%c\n",*p1,*p2);
	}while(p2++,*p1++!='\0');

	return 0;
}

void main(int argc,char ** argv){

	if(argc<=2){
		printf("please enter 2 string args!\n");
		exit(1);
	}
	
	printf("%d\n",strcmp(*(argv+1),*(argv+2)));
}

