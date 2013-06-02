#include <stdio.h>

int main(int argc,char ** argv){
	char str1[20]="hi,";
	char * p=str1;
	char * str2="tim";
	strcat(p,str2);
	printf("%s\n",str1);
}
