#include<stdio.h>
#include<stdlib.h>
#include"word.h"
int main(){
	FILE *ptr;
//	fprintf(stdin,"word.h");

	ptr = freopen("my.txt","r",stdin);
	if(ptr == NULL){
		printf("File cannot be opened\n");
		exit(0);
	}
	char a[50];

	printf("Hello world\n");
	read_word(a,49);
	printf("%s\n",a);
	fclose(ptr);


	return 0;
}

