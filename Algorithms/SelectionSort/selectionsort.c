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
void selectSort(int *arr,int n)
{
    int i,j,indexMin,p=0,c=0,s=0;
    for (i=0;i<n-1;i++)
    {
        indexMin = i;
        p++;
        for(j=i+1;j<n;j++)
        {
            if (arr[j]<arr[indexMin])
            {
                indexMin = j;
            }
            c++;
        }
        if(indexMin!=i)
        {
            int temp = arr[i];
            arr[i]=arr[indexMin];
            arr[indexMin]=temp;
            s++;
        }
        if (s==0)
        {
            break;
        }
        printArray(arr,n);
    }
    printf("Number of passes = %d\n",p);
    printf("Number of comparison = %d\n",c);
    printf("Number of swappings = %d\n",s);
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
    selectSort(arr,n);
}
