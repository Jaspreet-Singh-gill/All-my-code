/*program to copy a file from terminal */
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	FILE *source,*dest;
	int ch;
	if(argc != 3){
	       fprintf(stderr,"usage : fcp source dest \n");

	}
	if((source = fopen(argv[1],"rb")) == NULL){
		fprintf(stderr,"File %s not found \n",argv[1]);
	}

	if((dest = fopen(argv[2],"wb")) == NULL){
		fprintf(stderr,"File %s not be copied \n",argv[2]);

	}
	while((ch = getc(source)) != EOF){
	     putc(ch,dest);

        }
        putc(EOF,dest);
        fclose(source);
        fclose(dest);
        return 0;
}	
