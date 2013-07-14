#include <stdio.h>

int main(int argc,char ** argv){
	printf("%s\n",__STRING("int a=b;"));
	printf("%s\n",__STRING(int a=b;));
	return 0;      
}
