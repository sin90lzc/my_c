#include <stdio.h>
#include <stdlib.h>
#include <tim.h>
#include "student.h"

void initStudent(STUDENT * stdp,int n){
	int i=0;
	for(;i<n;i++,stdp++){
		fscanf(stdin,"%d %s %f %f %f",&stdp->num,stdp->name,&stdp->chinese,&stdp->math,&stdp->english);
		fgetc(stdin);//get char '\n'
	}	
	
}
void writeFile(STUDENT * stdp,int n,char * filename,char * operType){
	FILE * fp;
	if((fp=fopen(filename,operType))==NULL){
		printf("error:open file 't5_txt'\n");
		exit(1);
	}	
	int i=0;
	for(;i<n;i++,stdp++){
		fprintf(fp,"%5d%10s%6.1f%6.1f%6.1f%6.1f\n",stdp->num,stdp->name,stdp->chinese,stdp->math,stdp->english,stdp->average);
		if(ferror(fp)){
			printf("write file error!\n");	
		}
	}
	fclose(fp);
	if(ferror(fp)){
		printf("file close error!\n");
	}
}
void calAverage(STUDENT * stdp,int n){
	int i;
	for(i=0;i<n;i++,stdp++){
		float sum=0;
		sum=stdp->chinese+stdp->math+stdp->english;
		stdp->average=sum/3;		
	}
}
STUDENT * readFile(FILE * fp,STUDENT * std,int n){
	rewind(fp);
	int i;
	STUDENT * stdp=std;
	for(i=0;i<n;i++,stdp++){
		fscanf(fp,"%5d%10s%6f%6f%6f%6f",&stdp->num,stdp->name,&stdp->chinese,&stdp->math,&stdp->english,&stdp->average);
	}
}
/*
void sortStudent(STUDENT * std,int n,STUDENT ** stdps){
	int i,j;
	STUDENT * stdp=std;
	STUDENT * * stdpp=stdps;
	for(i=0;i<n;i++,stdpp++,stdp++){
		*stdpp=stdp;
	}
	stdpp=stdps;
	
	for(i=0;i<n-1;i++){
		stdpp=stdps;
		for(j=0;j<n-1-i;j++,stdpp++){
			if((*(stdpp))->average>(*(stdp+1))->average){
				stdp=*(stdp+1);
				*(stdp+1)=*(stdpp)
				*(stdpp)=stdp;
			}	
		}			
	}
}
*/

void sortStudent(STUDENT * std,int n){
	int i,j;
	STUDENT * stdp=std;
	//STUDENT * * stdpp=stdps;
	/*
	for(i=0;i<n;i++,stdpp++,stdp++){
		*stdpp=stdp;
	}
	stdpp=stdps;
*/	
	STUDENT temp;
	for(i=0;i<n-1;i++){
		stdp=std;
		for(j=0;j<n-1-i;j++,stdp++){
			if(stdp->average>(stdp+1)->average){
				temp=*(stdp+1);
				*(stdp+1)=*stdp;
				*stdp=temp;
			}	
		}			
	}
}


void insertStudent(STUDENT std,char * filename,int fileLength){
	FILE * fp=fopen(filename,"r+");
	if(fp==NULL){
		printf("error:open file:%s\n",filename);
		exit(1);
	}	
/*
	fprintf(fp,"%5d%10s%6.1f%6.1f%6.1f%6.1f\n",std.num,std.name,std.chinese,std.math,std.english,std.average);
	fclose(fp);
	if(ferror(fp)){
		printf("error:close the file:%s\n",filename);
		exit(1);
	}
*/

	int stdScore=std.average;
	int i;
	STUDENT temp1;
	int flag=0;
	while(!feof(fp)&&!flag){
		fscanf(fp,"%5d%10s%6f%6f%6f%6f\n",&(temp1.num),temp1.name,&(temp1.chinese),&(temp1.math),&(temp1.english),&(temp1.average));
		//printf("position:%ld",ftell(fp));
			//printf("%5d%10s%6.1f%6.1f%6.1f%6.1f\n",temp1.num,temp1.name,temp1.chinese,temp1.math,temp1.english,temp1.average);

		if(!flag&&temp1.average>=stdScore){
			flag=1;
			fseek(fp,-44,SEEK_CUR);
			fprintf(fp,"%5d%10s%6.1f%6.1f%6.1f%6.1f\n",std.num,std.name,std.chinese,std.math,std.english,std.average);
		}
/*
		if(flag){
			fprintf(fp,"%5d%10s%6.1f%6.1f%6.1f%6.1f\n",temp1.num,temp1.name,temp1.chinese,temp1.math,temp1.english,temp1.average);
		}
		
*/
	}	
	if(!flag){
		fseek(fp,0,SEEK_END);	
		fprintf(fp,"%5d%10s%6.1f%6.1f%6.1f%6.1f\n",std.num,std.name,std.chinese,std.math,std.english,std.average);
	}else{
		STUDENT T2;
		while(!feof(fp)){
			fscanf(fp,"%5d%10s%6f%6f%6f%6f\n",&(T2.num),T2.name,&(T2.chinese),&(T2.math),&(T2.english),&(T2.average));
			fseek(fp,-44,SEEK_CUR);
			fprintf(fp,"%5d%10s%6.1f%6.1f%6.1f%6.1f\n",temp1.num,temp1.name,temp1.chinese,temp1.math,temp1.english,temp1.average);
			temp1=T2;
		}	
	}
	fclose(fp);
	if(ferror(fp)){
		printf("error:close the file:%s\n",filename);
		exit(1);
	}
}
