#include<stdio.h>
#include <ctype.h>
#include<stdlib.h>
#define KEY '&'

int main(int argc,char *argv[])
{
	FILE *in ,*out;

	if(argc != 3){
		fprintf(stderr,"xor input file output file \n");
		exit(EXIT_FAILURE);
	}
	in = fopen(argv[1],"rb");
	if(in == NULL){
	fprintf(stderr,"FILE %s NOT FOUND\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	out = fopen(argv[2],"wb");
	if(out == NULL){
		fprintf(stderr,"FILE %s NOT FOUND\n",argv[2]);
		exit(EXIT_FAILURE);
	}
	short int test;
	char ch;
	while((test = getc(in)) != EOF){
		ch = ((char)(test)) ^ KEY;
		putc(ch,out);
	}
	fclose(out);
	fclose(in);

  return 0;
 
}
