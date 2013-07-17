#include <stdio.h>

#include "student.h"

int main(int argc,char ** argv){

	STUDENT tim={&tim,&tim,"tim",28};

	STUDENT rain={&rain,&rain,"rain",28};

	STUDENT mia={&mia,&mia,"mia",28};

	tim.next=&rain;
	tim.prev=&mia;
	rain.next=&mia;
	rain.prev=&tim;
	mia.next=&tim;
	mia.prev=&rain;

	//tim的下一个节点是rain
	printf("tim's next is :%s\n",tim.next->name);

	//rain的下一个节点是mia
	printf("rain's next is :%s\n",rain.next->name);

	//mia的下一个节点是tim
	printf("mia's next is :%s\n",mia.next->name);
	
}
