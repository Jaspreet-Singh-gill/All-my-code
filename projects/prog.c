#include<stdio.h>
#include"file1.h"
#include"file2.h"

int main(){
	extern int i;

	printf("hello world\n");
	printf("The value of i >s %d\n",i);

	f();
	return 0;
}


