#include <stdio.h>
void *duplicate(char *str);
int main(){
	char str[] = "Hello world";
	char *p;
	p = duplicate(str);
	printf("%s\n",p);
	return 0;
}

