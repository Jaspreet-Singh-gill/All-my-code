#include<stdio.h>
int main(){
	FILE *ptr;
	ptr = fopen("m.txt","w");
	fprintf(ptr,"hello world\n");
	fclose(ptr);
	return 0;
}
