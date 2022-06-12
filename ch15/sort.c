


void quicksort(int a[], int low, int high);
int partation(int a[], int low, int high);


void quicksort(int a[], int low, int high)
{
    int partation_index;

    if (low >= high)
        return;
    partation_index = partation(a, low, high);
    quicksort(a, low, partation_index - 1);
    quicksort(a, partation_index + 1, high);
    return;
}
int partation(int a[], int low, int high)
{
    int j = high;
    int i = low + 1;
    int partation_index = a[low];
    int temp;
    do
    {
        while (a[i] <= partation_index)
        {
            i++;
        }

        while (a[j] > partation_index)
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

