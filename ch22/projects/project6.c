#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	FILE *ptr;
	if(argc != 2){
		fprintf(stderr,"COMMAND FILENAME IS ITS USAGE \n");
		exit(EXIT_FAILURE);
	}
	ptr = fopen(argv[1],"r");
	if(ptr == NULL){
		fprintf(stderr,"FILE CANN'T BE OPEN\n");
		exit(EXIT_FAILURE);
	}
	char bytes[10];
	int loop_pos;
	int pos = 0;
	int ch;
	printf("Offset               Bytes              characters\n");
	printf("------  ------------------------------  ----------- \n");

	while((loop_pos = fread(bytes,1,10,ptr)) > 0){
		printf("%6d " ,pos);
		pos += loop_pos;
		for(int i =0 ; i < 10; i++){
		       if(i < loop_pos){
		       printf("%.2X ",bytes[i]);

		       }
	               else{
		       printf("   ");
		       }
		}
		for(int i = 0 ; i < 10; i++){
			if(i < loop_pos){
				printf("%c",(!isprint(bytes[i])) ? '.' : bytes[i]);
			}
			else
				printf(".");
		}

		printf("\n");



	/*for(int i = 0 ;i < pos ;i =+10){
		printf("%6d ",i);
		//loop_pos = ftell(ptr);
		for(int j = 0; i <10; i++){
			if(j < pos){
			ch = getc(ptr);

			printf("%.2X ",ch);
			}
			else{
				printf("   ");
			}
		}
		fseek(ptr,-10,SEEK_CUR);
		for(int i = 0; i < 10;i++){
			if(i < pos){
				ch = getc(ptr);
				if(!isprint(ch))
					ch = '.';
				printf("%c",ch);
			}
			printf(".");
		}
		printf("\n");
	}
*/
	}

	printf("\n");
}


