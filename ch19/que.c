#include<stdio.h>
#include "queque.h"
int main(){
	quque p;
	p = create();
	edquque(p,7);
	printf("%d\n",dlquque(p));
	for(int i = 0; i < 10; i++)
		edquque(p,i);
	printf("%d\n",get_first(p));
	printf("%d\n",get_last(p));
	printf("%d\n",get_first(p));
	printf("%d\n",dlquque(p));
	printf("%d\n",dlquque(p));
	printf("%d\n",dlquque(p));

	printf("%d\n",get_first(p));
	return 0;
}

