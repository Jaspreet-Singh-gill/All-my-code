#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool is_compress(char *ch){
	bool is_point = false;
	char *p = ch;
	while(*p++);

	for(; p >= ch && *p != '.';p--)
		;
	return ((strcmp(p,".rle")) ==0);

}
void compress(char *ch);
void un_compress(char *ch);
int main(int argc,char *argv[]){
	if(argc != 2){
		fprintf(stderr,"COMMPRESS : FILENAME\n");
		exit(EXIT_FAILURE);
	}
	if(is_compress(argv[1])){
		un_compress(argv[1]);
		printf("FILE %s uncompressed now\n",argv[1]);
	}
	else{
		compress(argv[1]);
		printf("FILE %s is compressed now\n",argv[1]);
	}
	return 0;
}

void compress(char *ch){
	char *outputfile = malloc(strlen(ch)+5);
	if(outputfile == NULL){
		fprintf(stderr,"MEMORY NOT AVILABLE\n");
		exit(EXIT_FAILURE);
	}
	strcpy(outputfile,ch);
	strcat(outputfile,".rle\0");
	FILE *in,*out;
	in = fopen(ch,"rb");
	if(in == NULL){
		fprintf(stderr,"file %s cann't be open\n",ch);
		exit(1);
	}
	out = fopen(outputfile ,"wb");
	if(out == NULL){
		fprintf(stderr,"File %s cann't be created\n",outputfile);
		exit(1);
	}
	char original;
	char cmp;
	char sequence;
	int pos;
	while((fread(&original,1,1,in)) > 0){
		sequence = 1;
		pos = ftell(in);
		while((fread(&cmp ,1,1,in)) > 0 && cmp == original){
			sequence++;
		}
		fwrite(&sequence,1,1,out);
		fwrite(&original,1,1,out);
		fseek(in,pos+(sequence-1),SEEK_SET);
	}

}
void un_compress(char *ch){
	char *outputfile = malloc(strlen(ch)-3);
	if(outputfile == NULL){
		fprintf(stderr,"MEMORY NOT AVILABLE\n");
	       	exit(EXIT_FAILURE);
	}
        strncpy(outputfile,ch,strlen(ch)-4);
       // strcat(outputfile,".rle\0");
        FILE *in,*out;
        in = fopen(ch,"rb");
        if(in == NULL){
                fprintf(stderr,"file %s cann't be open\n",ch);
                exit(1);
        }
        out = fopen(outputfile ,"wb");
        if(out == NULL){
                fprintf(stderr,"File %s cann't be created\n",outputfile);
                exit(1);
        }
	char original;
	char sequence;
	int i = 0;
	while(fread(&original,1,1,in) > 0){
		if(i %2 == 0){
			sequence = original;
		}
		else{
			for(int i = 0; i<sequence;i++){

			fwrite(&original,1,1,out);}
		}

		i++;
	}
}



