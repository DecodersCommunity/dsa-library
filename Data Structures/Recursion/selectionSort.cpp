#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    int min = arr[0];
    int minIndex;
    for (int i = 0; i < n;; i++)
    {
        if (arr[i] < minminIndex)
        {
            min = arr[i];
            minIndex = i;
        }
    }
    swap(arr,count,minIndex);
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    selectionSort(arr, n - 1);
    // Array printing after sorting
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}