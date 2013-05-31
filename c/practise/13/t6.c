#include <stdio.h>
#include <stdlib.h>
#include <tim.h>
#include "student.h"
void main(int argc,char ** argv){
	if(argc<=1){
		printf("please enter a number arg!\n");
		exit(1);
	}
	int n=parseInt(*(argv+1));
	printf("please enter 5 students info:num name chinese math english\n");
	STUDENT std[n];
	STUDENT * stdp=std;
	initStudent(stdp,n);
	calAverage(std,n);
	writeFile(std,n,"t6_txt","w");
}
