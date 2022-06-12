#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *ptr;
	ptr = fopen("my.txt","r");
	if(ptr == NULL){
		printf("File not be open\n");
		exit(EXIT_FAILURE);
	}
	putc('w',ptr);
	if(ferror(ptr) == 1){
		printf("Writing to file in read mode \n");
		clearerr(ptr);
	}

	if(!ferror(ptr)){
		printf("The error has been cleared\n");
		}
	int ch = 0;
	while(fgetc(ptr)!= EOF)
		ch++;
	printf("%d\n",ch);
	if(feof(ptr)){
		printf("File has reached at the end \n");
	}
	fclose(ptr);



	return 0;
}

