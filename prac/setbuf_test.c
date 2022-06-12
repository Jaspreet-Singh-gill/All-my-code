#include<stdio.h>
#include<stdlib.h>
#include"word.h"
#define size 40
int main(){
	FILE *ptr ;
	char ch[90];
	if((ptr = fopen("ui.txt","w")) == NULL){
		printf("Cann't open file\n");
		exit(EXIT_FAILURE);
	}
	 char *p = malloc(BUFSIZ);
	/*if(p == NULL){
		printf("memory not avialable for file\n");
		exit(EXIT_FAILURE);
	}*/
	setbuf(ptr,ch); /*) != 0){
		printf("Buffer can't be setup\n");
		exit(EXIT_FAILURE);
	}*/

	printf("Enter the message :");
	read_word(ch,90);
	fprintf(ptr,"%s\n",ch);
	fflush(ptr);
	free(p);

	return 0;
}

