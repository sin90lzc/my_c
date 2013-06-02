#include<stdio.h>
#define NUM 2
#define STR(a) #a
#define E(a,b) (int)a##e##b
void main(){    
    printf(STR(NUM)"\n");//输出NUM，并不会展开NUM
    printf("%d""\n",E(NUM,NUM));//会编译出错
}
