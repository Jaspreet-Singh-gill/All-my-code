#include<stdio.h>
#define INT_SIZE (sizeof(int)*8)-1
#include "bit_printer.h"
unsigned int reverse_bit(unsigned int a);

int main(){
	unsigned int num = 0x1086,new;
	printf("Bytes of %x\n",num);
	print_bytes(num);
	printf("Bytes of %x in reverse order\n",new = reverse_bit(num));
	print_bytes(new);


	return 0;

}
unsigned int reverse_bit(unsigned int     a){
	unsigned int num = 0;
	for(int i = INT_SIZE; i >=0; i--){
		if(a & (1 << i)){
			num = num | (1 <<(INT_SIZE) -  i);
		}
	}
	return num;
}
