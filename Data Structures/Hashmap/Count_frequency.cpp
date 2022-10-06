//  Contributed by - Pakhi Vashishth <pakhivashis182001@gmail.com>
//count frequency of each element using map
#include <bits/stdc++.h>
using namespace std;

void frequency(int arr[],int n){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++)
     map[arr[i]]++;
 
    // Traverse through map and print frequencies
    for (auto x : map)
        cout << x.first << " " << x.second << endl;
}
 
int main()
{
    int arr[] = {10,5,10,15,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    frequency(arr, n);
    return 0;
}
