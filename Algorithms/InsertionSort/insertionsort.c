// Contributed by - Byomakesh Panda <byomakeshpanda210@gmail.com>

#include <stdio.h>
void printArray(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void insertionSort(int *a,int n )
{
    int i,j,p=0,c=0;
    for (i=1;i<n;i++) //For passes
    {
        int key=a[i];
        int j = i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1] = a[j];
            j--;
            c++;
        }
        if (a[j]<key)
        {
            c++;
        }
        a[j+1]=key;
        p++;
        printArray(a,n);
    }
    printf("Number of passes = %d\n",p);
    printf("Number of comparisons = %d\n",c);
}
void main()
{
    int arr[20];
    int i,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printArray(arr,n);
    insertionSort(arr,n);
}
