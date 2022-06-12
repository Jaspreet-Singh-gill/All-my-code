#include<stdio.h>
int main(){
	FILE *name = freopen("num","r",stdin);
	printf("Done \n");
	char a[62];
	scanf("%s",a);
	printf("%s\n",a);
	scanf("%s",a);
	printf("%s\n",a);




	fclose(name);
	return 0;
}
