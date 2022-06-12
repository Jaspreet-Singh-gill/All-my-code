#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc ,char *argv[]){
	if(argc != 2){
		fprintf(stderr,"comand name filenane is its usage\n");
		exit(EXIT_FAILURE);
	}
	FILE *ptr;
	if((ptr = fopen(argv[1],"r+")) == NULL){
		fprintf(stderr,"File %s cann't be open\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	int ch;
	while((ch = getc(ptr)) != EOF)
	{
		if(ch >= 'a' && ch <= 'z')
			putc((ch-'a')+'A',stdout);
		else
			putc(ch,stdout);


	}	
	printf("\n");
	return 0;
}

