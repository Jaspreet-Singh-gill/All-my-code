#include<stdlib.h>
int *create_array(int n,int init){
	int *ptr;
	ptr = (int *)malloc(n*sizeof(int));
	if(ptr != NULL){
		for(int i = 0; i <n;i++){
			ptr[i] = 0;
		}
		return ptr;
		
	}

	else
		return NULL;
}
