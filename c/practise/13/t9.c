#include <stdio.h>

#include <stdlib.h>

#include <tim.h>

#include "student.h"


void main(){
	printf("please enter a studnet to insert to file 't7_txt'\n");
	STUDENT more;
	initStudent(&more,1);
	calAverage(&more,1);
	insertStudent(more,"t7_txt",1);			
}
