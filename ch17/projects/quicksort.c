#include <stdio.h>
#include"quicksort.h"
/*void array_printer(int a[])
{
    for (int i = 0; i < N; i++)
    {
        if (i == N)
            printf("%d", a[i]);
        else
            printf("%d  ", a[i]);
    }
}*/

void quicksort(struct part a[], int low, int high){
    int partation_index;

    if (low >= high)
        return;
    partation_index = partation(a, low, high);
    quicksort(a, low, partation_index - 1);
    quicksort(a, partation_index + 1, high);
    return;
}
int partation(struct part a[], int low, int high)
{
    int j = high;
    int i = low + 1;
    struct part partation_index = a[low];
    struct part temp;
    do
    {
        while (a[i].number <= partation_index.number)
        {
            i++;
        }

        while (a[j].number > partation_index.number)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    if (j <= i)
    {
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
    }
    return j;
}

