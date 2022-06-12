#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	FILE *ptr;
	if(argc != 2){
		printf("Can open file only\n");
		exit(EXIT_FAILURE);
	}


	if((ptr = fopen(argv[1],"r")) == NULL){
		printf("Enter correct file name\n");
		exit(EXIT_FAILURE);
	}
	printf("File can be open %s \n",argv[1]);
	fclose(ptr);
	return 0;
}

