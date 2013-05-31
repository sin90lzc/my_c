#include <stdio.h>
#define DEBUG 1

void main(){
	#if DEBUG==1
		printf("DEBUG\n");
	#else
		printf("NODEBUG\n");
	#endif
}
