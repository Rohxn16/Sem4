#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;
    
    if(r < n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr,n,largest);
    }
}

void heapsort(int *arr, int n)
{
    for(int i = n/2-1; i >= 0; i--)
        heapify(arr,n,i);
    
    for(int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr,i,0);
    }
}

int main(int argc, char const *argv[])
{

    printf("Enter the size of the array\n");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);
    heapsort(arr,n);
    printArray(arr,n);

    return 0;
}
