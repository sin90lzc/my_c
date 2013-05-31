#include <stdio.h>
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
