#include<stdio.h>
#include<stdlib.h>
#include"word.h"
#include<string.h>
int main(){
	char a[60];
	FILE *buffer = NULL;
	if((buffer = tmpfile()) == NULL){
		printf("Not enough storage\n");
		exit(EXIT_FAILURE);
	}
	printf("ENTER THE MESSSAGE : ");
	read_word(a,59);
	fprintf(buffer,"%s\n",a);
	memmove(stdout,buffer,(59));

	fclose(buffer);
	return 0;
}


