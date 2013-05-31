#include <stdio.h>

#include <stdlib.h>

#include <tim.h>

#include "student.h"

void main(){		
	STUDENT sixth;
	printf("please enter the 6th student's info:\n");	
	initStudent(&sixth,1);
	sixth.average=(sixth.chinese+sixth.math+sixth.english)/3;
	STUDENT std[6];
	FILE * fp=fopen("t7_txt","r");
	if(fp==NULL){
		printf("error:open the file!");
		exit(1);
	}	
	readFile(fp,std,5);
	fclose(fp);
	if(ferror(fp)){
		printf("error:close the file!");
		exit(1);
	}
	std[5]=sixth;
	sortStudent(std,6);
	writeFile(std,6,"t8_txt","w");
}
