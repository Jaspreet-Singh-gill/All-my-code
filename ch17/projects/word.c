#include "word.h"
#include <stdio.h>

int read_word(){
	int ch;
	ch = getchar();
	if(ch =='\n' || ch == '\t')
		return ' ';
	return ch;
}

void read_line(char *a,int len){
	int pos = 0,ch;
	while((ch = read_word()) ==' ')
		;
	while(ch != ' ' && ch != EOF)
	{
		if(pos <len)
			a[pos++] = ch;
	
		ch = read_word();

	}
	a[pos] = '\0';
}

