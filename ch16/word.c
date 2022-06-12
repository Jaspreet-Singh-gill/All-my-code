
#include "word.h"
#include<ctype.h>



void read_line(char nventory[],int num)
{
	int pos = 0,ch;
	while(isspace(ch = getchar()))
		;
	while(ch != '\n'){
 		if(pos < num)
		{
			nventory[pos++] = ch;
		
		}

		ch = getchar();
	}
	nventory[pos] = '\0';
}

