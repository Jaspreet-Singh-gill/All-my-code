#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include "read_line.h"
#define MAX_LEN 20
#define MAX_WORD_LEN 22
int compare(const void *w1, const void *w2)
{
    return strcmp(*(char **)w1, *(char **)w2);
}

int main(){
	char *word[20],*ptr = NULL;
	int num = 0;
	for(int i = 0;i < MAX_LEN;i++){
	       	ptr = malloc(MAX_WORD_LEN+1);
		printf("Enter the word:");
		//fgets(ptr,MAX_WORD_LEN + 1, stdin);
		read_line(ptr,MAX_WORD_LEN +1);

		if(ptr[0] == '\n')
			break;

		
		word[i] = ptr;
		num++;
	}
	qsort(word,num,sizeof(char *),compare);
	for(int i = 0;i < num;i++)
		printf("%s ",(word[i]));

	
	printf("\n");
	return 0;
}

