#include<stdio.h>
#include<ctype.h>
#include"read_line.h"

int read_line(char *str,int len){
	int ch,pos=0;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n' && ch != EOF){
		if(pos < len)
			str[pos++] = ch;
		ch = getchar();
	}
	str[pos] = '\0';
	return pos;
}

