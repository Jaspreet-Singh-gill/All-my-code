#include<stdio.h>
#include<string.h>
#include"line.c"
#include"word.c"
#define max_word 20
int main(void){
	char word[max_word+2];
	int word_len;
	clear_line();
	for(;;){
		read_word(word,max_word+1);
		word_len = strlen(word);
		if(word_len ==0){
			flush_line();
			return 0;
		}
	//	if(word_len > max_word)
	//		word[max_word]='*';
		if(word_len+1 > space_remaining())
		{
			write_len();
			clear_line();
		}
		add_word(word);
	}
	return 0;

}

