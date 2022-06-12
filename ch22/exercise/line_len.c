#include<stdio.h>
#include<stdlib.h>
int line_length(char *filename){
	FILE *ptr;
	int ch;
	int num;
	if((ptr = fopen(filename,"r")) != NULL){
		while((ch = fgetc(ptr)) != EOF)
			if(ch == '\n')
				return ftell(ptr) - 1;
	}
	else
		return 0;

	num = ftell(ptr)-1;
	fclose(ptr);
	return num;
}

int main(int argc,char *argv[]){
	int n;
	if(argc != 2){
		fprintf(stderr,"command filename is its usage\n");
		exit(EXIT_FAILURE);
	}

	n = line_length(argv[1]);
	printf("The number of line in %s is %d\n",argv[1],n);
	return 0;
}

