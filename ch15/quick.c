#include <stdio.h>
//#include"sort.c"
#define N 10 
void array_printer(int a[]);
void quicksort(int a[], int low, int high);
int main()
{
    int a[N];
    for (int i = 0; i < N; i++)
    {
        printf("Enter the %d number :", i + 1);
        scanf("%d", &a[i]);
    }
    array_printer(a);
    quicksort(a, 0, N - 1);
    printf("\n");
    array_printer(a);
    return 0;
}

void array_printer(int a[])
{
    for (int i = 0; i < N; i++)
    {
        if (i == N)
            printf("%d", a[i]);
        else
            printf("%d  ", a[i]);
    }
}

