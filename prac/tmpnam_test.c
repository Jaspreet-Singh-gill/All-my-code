#include<stdio.h>
#include<stdlib.h>
#include"word.h"
#include<string.h>
int main(){
	char a[L_tmpnam];
	FILE *buffer;
	if((tmpnam(a))  == NULL){
		printf("Not enough storage\n");
		exit(EXIT_FAILURE);
	}
	if((buffer = fopen(a,"w")) == NULL){
                printf("Not enough storage\n");
                exit(EXIT_FAILURE);
        }
	char data[60];
	printf("ENTER THE MESSSAGE : ");
	read_word(data,59);
	fprintf(buffer,"%s\n",data);
	memcpy(stdout,buffer,(59));

	fclose(buffer);
	remove(a);

	return 0;
}


