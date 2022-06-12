#include<string.h>
#include<stdlib.h>

void *duplicate(char *str){
	int len;
	char *ptr;
	len = strlen(str)+1;
	ptr = (char *)malloc(len);
	strcpy(ptr,str);

	return ((ptr ==NULL)?NULL:ptr);
}

