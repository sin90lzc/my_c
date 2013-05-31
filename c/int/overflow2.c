#include <stdio.h>
//unsigned赋值给signed或signed赋值给unsigned，在内存中都是原封不动地copy
void main(){
	unsigned int ua,ub;
	signed int sa,sb;
	sa=-1;
	ua=4294967295;
	sb=ua;
	ub=sa;
	printf("%d\n",ua);
	printf("%u\n",sb);
}
