#include<stdio.h>
#include<ctype.h>
typedef unsigned char BYTE;
int main(){
	unsigned int addr;
	int i,n;
	BYTE *ptr;
	printf("THE ADDRESS OF MAIN IS %X \n",(unsigned int)main);
	printf("THE ADDRESS OF VARIABLE ADDR IS %X \n",(unsigned int)&addr);
	printf("Enter the address in hex format");
	scanf("%X",&addr);
	printf("Enter the number of bytes : "); 
	scanf("%d",&n);
	printf("\n");
	ptr = (BYTE *)addr;
	printf("\n");
	for(; n > 0; n -= 10){
		printf("%8X",(unsigned int )ptr);
	for( i = 0; i < 10 && i < n;i++)
		printf("%.2x",*(ptr+i));
	for(; i < 10; i++)
		printf("   ");
	printf("  ");
	for(i = 0; i < 10 && i <n;i++){
		BYTE ch = *(ptr+i);
		if(!isprint(ch))
			ch = '.';
		printf("%c",ch);
	}
	printf("\n");
	ptr += 10;
	}
	return 0;
}	
