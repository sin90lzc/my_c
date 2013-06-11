/**
 * 在处理带#并需要迭代宏时，是不会展开宏的，需要使用中间宏。
 *
 */
#include <stdio.h>

#define NUM 2
#define STR(a) _STR(a)
#define _STR(a) #a
#define	E(a,b) _E(a,b)
#define _E(a,b) (int)a##e##b

int main(){    
    printf("%s\n",STR(NUM));//能正确地输出2
    printf("%d""\n",E(NUM,NUM));//能正确地输出200
    return 0;
}
