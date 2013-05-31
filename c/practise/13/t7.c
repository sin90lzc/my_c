#include <stdio.h>
#include <stdlib.h>
#include <tim.h>
#include "student.h"

void main(){
	FILE * fp=fopen("t6_txt","r");
	if(fp==NULL){
		printf("error: open file\n");
		exit(1);
	}
	STUDENT std[5];
	readFile(fp,std,5);
	sortStudent(std,5);
	STUDENT * stdp=std;
	writeFile(stdp,5,"t7_txt","w");	
	fclose(fp);
	if(ferror(fp)){
		printf("error:close file!\n");
	}
}
