#include <stdio.h>
#include <tim.h>
#include <stdlib.h>
void main(int argc,char ** argv){
	if(argc<=1){
		printf("please enter a number argument!\n");
		exit(1);
	}
	int n=parseInt(*(argv+1));
	char * month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	printf("%s\n",*(month+n-1));

}
