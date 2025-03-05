#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1 )
        {
            j--;
        }

        if ( i < j)
        swap(&arr[i],&arr[j]);
        
    }
    swap(&arr[low],&arr[j]);
    return j;

}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);
    }
}

void printarray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");    
}

int main(int argc, char *argv[])
{

    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printarray(arr,n);
    quicksort(arr, 0, n-1);
    printarray(arr,n);
    return 0;

}