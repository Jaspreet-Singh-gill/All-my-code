#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[11];	//= malloc(20*4);
	FILE *ptr;
	if((ptr = fopen("num","r+")) == NULL)
		exit(EXIT_FAILURE);
	fread(a,4,10,ptr);
	printf(" the number are : ");
	for(int i = 0; i < 10; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	/*
	freadfread(a,4,10,ptr);(a,4,10,ptr);
	*/
	fclose(ptr);
	return 0;
}

