#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
int count_ch(FILE *ptr);
int count_word(FILE *ptr);
int count_lines(FILE *ptr);
int main(int argc,char *argv[]){
	FILE *ptr;
	if(argc < 2){
		fprintf(stderr,"cammand filename is its usage\n");
		exit(EXIT_FAILURE);
	}
	ptr = fopen(argv[1],"r");
	if(ptr == NULL){
		fprintf(stderr,"File cann't be open\n");
		exit(EXIT_FAILURE);
	}
	printf("THE NUMBER OF CHARACTER IS %d \n",count_ch(ptr));
	printf("\n");
	printf("THE NUMBER OF WORD IS %d \n",count_word(ptr));
	printf("\n");
	printf("THE NUMBER OF LINES  IS %d \n",count_lines(ptr));
        printf("\n");
	return 0;
}

int count_ch(FILE *ptr){
	fseek(ptr,0,SEEK_END);
	return ftell(ptr);
}
int count_word(FILE *ptr){
	rewind(ptr);
	int num = 0, flag = 0;
	int ch;

	while((ch = getc(ptr)) != EOF){
		if(isspace(ch)){
			if(!flag){
				num++;
				flag = true;
			}
		}

		else
			flag = false;

	}


	return num;
}

int count_lines(FILE *ptr){
	rewind(ptr);
	int num =0,ch;
	while((ch = getc(ptr)) != EOF){
		if(ch == '\n')
			num++;
	}
	return num;
}
