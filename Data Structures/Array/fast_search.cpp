#include <iostream>
using namespace std;


int binarySearch(int arr[], int start, int end, int ele)
{
    if (end >= start) {
        int mid = (start+end)/2;

        if (arr[mid] == ele)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(void)
{
   int n;
   cout<<"Enter the size of Array: ";
   cin>>n;
   int A[n];
   cout<<" Enter the Array: ";
   for(int i=0;i<n;i++)
     cin>> A[i];

    int ele;
    cout<<"Enter the element you wants to search: ";
    cin>>ele;
    int result = binarySearch(arr, 0, n - 1, ele);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
