/**
 *
 * 在处理带#并需要迭代宏时，是不会展开宏的，需要使用中间宏。
 * 正确的方式请看文件define_correct.c
 *
 */

#include<stdio.h>
#define NUM 2
#define STR(a) #a
#define E(a,b) (int)a##e##b
void main(){    
    printf(STR(NUM)"\n");//输出NUM，并不会展开NUM
    printf("%d""\n",E(NUM,NUM));//会编译出错
}
