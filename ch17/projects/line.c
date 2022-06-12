#include "line.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_LINE_LEN 60
struct node{
	char word[21];
	struct node *next;
};
struct node *line = NULL,*line_ptr = NULL;

int num_word = 0;
int line_len = 0;
void clear_line(){
	line_len = 0;
	num_word = 0;
	line =NULL;
	struct node *ptr = line_ptr;
	while(ptr != NULL){

		free(ptr);
		ptr = ptr->next;
	}


}
void add_word(char *a){
	struct node *ptr;

	if(num_word > 0){
		ptr = line;
		line = malloc(sizeof(struct node));
		ptr->next =line;
		line_len++;

	}

	if(line == NULL)
	{
		line = malloc(sizeof(struct node));
		line_ptr = line;
		}
	strcpy(line->word,a);

	line_len += strlen(a);
	num_word++;
}

int space_remaining(){
	return MAX_LINE_LEN - line_len;
}
void write_line(){
	struct node *ptr = line_ptr;
	int extra_space,space_to_insert;
	int word_count =0;
	extra_space = space_remaining();
	while(word_count < line_len && line_ptr != NULL){
		printf("%s",line_ptr->word);
		if(num_word > 1){
		space_to_insert = extra_space /(num_word-1);
			for(int i = 1; i <= space_to_insert +1; i++)
				putchar(' ');
			extra_space -= space_to_insert;
		}

			num_word--;
			word_count += strlen(line_ptr->word);
			line_ptr = line_ptr->next;


	}
	putchar('\n');
	
}

/*void flush_line(){
	struct node *ptr;
	ptr = line_ptr;
	for(;ptr != NULL;ptr = ptr->next)
		scanf("%s ",ptr->word);


}*/
void flush_line(void)
{
    if (line_len > 0) {
        struct node *entry = line_ptr;
        int i;
        for (i = 0, entry = line; entry; i++, entry = entry->next) {
            if (i > 0 && entry->next != NULL)
                putchar(' ');
            printf("%s ", entry->word);
        }
    }
    printf("\n");
    clear_line();
}

