#include <stdio.h>

void sorting(int arr[], int n)
{
    int temp,j,i;
    for(int i=1;i<n;i++)
    {
    temp=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>temp)
    {
    arr[j+1]=arr[j];
    j--;
    }
    arr[j+1]=temp;
    }
     
     printf("\nThe numbers in ascending order are :-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{

    int n;
    printf("Enter the number of elements to be sorted :");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d : ",(i+1));
        scanf("%d",&arr[i]);
    }
    sorting(arr,n);

    return 0;
}
