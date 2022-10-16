// Contributed by - Byomakesh Panda <byomakeshpanda210@gmail.com>
#include <stdio.h>
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t;
}
int partition(int arr[],int start,int end)
{
    int pivot = arr[end];
    int i = start-1;
    for (int j= start;j<=end-1;j++)
    {
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[end]); 
    return (i + 1);
}
void quicksort(int arr[],int start, int end)
{
    if (start<end)
    {
        int p;
        p = partition(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d\t",arr[i]); 
    printf("\n"); 
} 
int main()
{
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Initial Array:-\n");
    printArray(arr,n);
    quicksort(arr, 0, n - 1); 
    printf("Sorted Array:-\n"); 
    printArray(arr, n);
    return 0;
}
