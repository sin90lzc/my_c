#include <stdio.h>
#include <stdarg.h>
void f(void)__attribute__((weak));
void exitnow(){
	printf("exit!\n");
}
void exitnow()__attribute__((noreturn));
int main(){
	if(!f){
		printf("f is 0!\n");
		exitnow();
	}else{
		f();
	}
	return 0;
}

