#include<stdio.h>
#include <stddef.h>
struct s{
	char a;
	int b[2];
	float c;
};
int main(){
	printf("size of offsetof is %d\n",offsetof(struct s ,a));
	printf("size of offsetof is %d\n",offsetof(struct s ,b));
	printf("size of offsetof is %d\n",offsetof(struct s ,c ));
	printf("actual size in memory is %d\n",sizeof(struct s));
	return 0;
}

