#include <stdio.h>

int main(int argc,char ** argv){
	enum weekday{sun,mon,tue,wed,thr,fri,sat};
	printf("%d,%d,%d,%d,%d,%d,%d\n",sun,mon,tue,wed,thr,fri,sat);

	typedef enum weekday WEAKDAY;
	
	WEAKDAY birth=sat;

	printf("mybirth:%d\n",birth);

	WEAKDAY * pw=NULL;
	

}
