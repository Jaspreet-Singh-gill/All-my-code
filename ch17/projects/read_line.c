#include<stdio.h>
#include<ctype.h>
#include"read_line.h"

int read_line(char *str,int len){
	int ch = 'h',pos=0;

	while(ch != '\n' && ch != EOF){
		ch = getchar();
		if(ch == '\n')
			break;


		if(pos < len)
			str[pos++] = ch;
	}
	str[pos] = '\n';
	return pos;
}

