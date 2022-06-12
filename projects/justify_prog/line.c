#include "line.h"
#include<stdio.h>

#include <string.h>
#define MAX_LINE_LEN 60

int num_word = 0;
int line_len = 0;
char line[MAX_LINE_LEN+1];

void clear_line(){
	line_len = 0;
	num_word = 0;
	line[0] = '\0';
}
void add_word(char *a){
	if(num_word > 0){
		line[line_len] = ' ';
		line[line_len+1] = '\0';
		line_len++;
	}
	strcat(line,a);
	line_len += strlen(a);
	num_word++;
}

int space_remaining(){
	return MAX_LINE_LEN - line_len;
}
void write_line(){
	int extra_space,space_to_insert;
	extra_space = space_remaining();
	for(int i = 0;i < line_len;i++){
		if(line[i] != ' ')
			putchar(line[i]);
		else{
			space_to_insert = extra_space /(num_word-1);
			for(int j = 1; j <= space_to_insert +1; j++)
				putchar(' ');
			extra_space -= space_to_insert;
			num_word--;
	 	}
	}
	putchar('\n');
	
}

void flush_line(){
	puts(line);
}

