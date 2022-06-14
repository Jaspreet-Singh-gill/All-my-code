#include<stdio.h>
#include"word.h"

int check_space(void);


int check_space(void){
	int ch;
	ch = getchar();
	if(ch == '\n' || ch == '\t')
		return ' ';

	
	return ch;
}


int read_word(char *a,int len){
	int ch ,pos = 0;
	while((ch = check_space()) == ' ')
		;


	while(ch != '\n' && ch !=EOF)
	{
		if(pos <len)
			a[pos++] = ch;
		ch =getchar();

	}
	a[pos] = '\0';


	return pos;
}

