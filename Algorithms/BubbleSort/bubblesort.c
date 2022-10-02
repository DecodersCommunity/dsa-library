// Contributed by - Byomakesh Panda <byomakeshpanda210@gmail.com>

#include <stdio.h>
void printArray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void bubbleSort(int *a,int n)
{
    int i,j,p=0,c=0,s=0;
    for (i = 0 ;i<n-1;i++) //for number of passes
    {
         int flag=0;
        for(j = 0;j<n-1-i;j++) //for number of comparisions
        {
            if(a[j]>a[j+1]) //For number of swappings
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1] = temp;
                s++;
                flag++;
            }
            c++;
        }        
        if(flag==0)
        {
            break;
        }
        printArray(a,n);
        p++;
    }

    printf("Number of passes = %d\n",p);
    printf("Number of comparison = %d\n",c);
    printf("Number of swappings = %d\n",s);
}
void main()
{

    int a[15];
    int i,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    // printArray(a,n);
    bubbleSort(a,n);
}
