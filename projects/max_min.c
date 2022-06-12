#include<stdio.h>
#define N 10
void max_min(int a[],int n,int *max,int *min);
int main(){
	int a[N],max,min;
	printf("Enter the numbers:");
	for(int i = 0; i< N;i++)
		scanf("%d",&a[i]);
	max_min(a,N,&max,&min);
	printf("the largest number : %d\n",max);
	printf("The smallest number : %d\n",min);
	return 0;
}

void max_min(int a[],int n,int *max,int *
min){
	*max = *min = a[0];
	for(int i = 1; i <n;i++)
	{
		if(a[i] > *max)
			*max = a[i];
		else if(a[i] < *min)
			*min = a[i];
	}
}

		
