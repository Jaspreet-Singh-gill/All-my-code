#include <stdio.h>
#include <string.h>
#include "bit_printer.h" 
char *bit_string(int num);
void print_bytes(int num){
	for(int i = 3 ; i >= 0;i--){ 
		printf(" %s",bit_string(num >>( i* 8)));
				}
	printf("\n");

}

char *bit_string(int num){ 
static char a[9];
a[0] = '\0';


for(int i = 0x80; i >0; i >>= 1){
    strcat(a,(num & i ? "1":"0"));
    }
    return a;
    }

