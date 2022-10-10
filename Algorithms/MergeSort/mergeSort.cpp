#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;

    while (i <= m and j <= e)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    // this loop will break when one of the array is completed

    // copy remaining elements from left arr

    while (i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }
    // copy remaining elements from right arr
    while (j <= m)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // copy back elements from temp to original array
    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[k];
        k++;
    }
    return;
}

void mergesort(vector<int> &arr, int s, int e)
{
    //base case
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    return merge(arr, s, e);
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = arr.size() - 1;
    mergesort(arr, s, e);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}