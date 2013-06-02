/*
 *
 * 还需要装上csope去看下va_相关宏定义
 *
 */
#include <stdio.h>
#include <stdarg.h>
 
void xprintf(const char * format,...){
     const char * p=format;
     va_list vp;
     va_start(vp,format);
     int ival=0;
     while(*p){
         if(*p!='%'){
             putchar(*p);    
         }else{
             switch(*++p){
                 case 'd':
                     printf("%d",va_arg(vp,int));
                     break;
                 case 'x':
                     printf("%x",va_arg(vp,int));
                     break;
                 case 'f':
                     printf("%f",va_arg(vp,double));
                     break;
                 case 's':
                     puts(va_arg(vp,char *));
                     break;
		case '%':
			putchar('%');
			break;
                 default:
                     putchar('%');
                     putchar(*p);
             }
         }
 
         p++;
     }
     va_end(vp);
 }
 int main(int argc,char ** argv){
     xprintf("%%s:%s%%d:%d\n%%f:%f\n%%x:%x\n","abc",1,1.23,890);
 }
