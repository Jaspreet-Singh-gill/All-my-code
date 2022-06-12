#include <stdio.h>
#include "stackADT2.h"
int main(){
	stack s1,s2;
	int n;
	s1 = create(4);
	s2 = create(4);
	push(s1,1);
	push(s1,2);
	n = pop(s1);
	printf("Poped %d from s1\n",n);
	push(s2,n);
	n = pop(s1);
	printf("Poped %d from s1\n",n);
	push(s2,n);
	destroy(s1);
	while(!is_empty(s2))
		printf("Poped %d from s2\n",pop(s2));
	push(s2,3);
	make_empty(s2);
	if(is_empty(s2))
		printf("S2 is empty \n");
	else
		printf("S2 is not empty \n");
	destroy(s2);
	return 0;
}

