struct student{
	int num;
	char name[20];
	float chinese;
	float math;
	float english;	
	float average;
};

typedef struct student STUDENT;

void writeFile(STUDENT * stdp,int n,char * filename,char * operType);
void initStudent(STUDENT * stdp,int n);
void calAverage(STUDENT * stdp,int n);
STUDENT * readFile(FILE * fp,STUDENT * std,int n);
void sortStudent(STUDENT * std,int n);
void insertStudent(STUDENT std,char * filename,int fileLength);
