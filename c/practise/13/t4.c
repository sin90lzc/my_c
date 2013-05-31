#include <stdio.h>
#include <stdlib.h>
#include <tim.h>

void main(){
	char str[100];
	fscanf(stdin,"%s",str);
	char * p=str;
	while(*p!=EOS){
		if(*p>='a' && *p<='z'){
			*p+='A'-'a';
		}
		p++;
	}

	p=str;
	FILE * fp;
	if((fp=fopen("t4_txt","w"))==NULL){
		printf("error:open the file t4_txt\n");
		exit(1);
	}
	fputs(p,fp);
	fclose(fp);
	if(ferror(fp)){
		printf("error:close the file t4_txt\n");
		exit(1);
	}

}
