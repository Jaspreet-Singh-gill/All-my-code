#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	FILE *ptr;
	int ch;
	if(argc <2){
		fprintf(stderr,"CAMMAND FILNAME .... IS ITS USAGE\n");
		exit(EXIT_FAILURE);
	}
	for(int i = 1; i < argc;i++){
		ptr = fopen(argv[i],"r");
		if(ptr == NULL)
			fprintf(stderr," %s file cann't be found\n",argv[i]);
		else{
			while((ch = getc(ptr)) != EOF)
					putchar(ch);
			printf("\n");
			printf("File %s has been printed\n",argv[i]);
			printf("\n");

			fclose(ptr);
			}
		}
	return 0;
}

		
			
