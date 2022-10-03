// Contributed by - Byomakesh Panda <byomakeshpanda210@gmail.com>

#include <stdio.h>
void merge(int a[],int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int k=0;
    int b[r-l+1];
    while(i<=mid && j<=r)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while(j<=r)
    {
        b[k++]=a[j++];
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    for (k=0;k<r-l+1;k++)
    {
        a[k+l]=b[k];
    }
}
void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    else
    {
        return;
    }
}
void display(int arr[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void main()
{
    int n,i;
    int arr[10];
    printf("Enter the number of elements:-\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);        
    }
    printf("Initial Array:-\n");
    display(arr,n);
    printf("\nAfter sorting:-\n");
    mergeSort(arr,0,n-1);
    display(arr,n);
}
