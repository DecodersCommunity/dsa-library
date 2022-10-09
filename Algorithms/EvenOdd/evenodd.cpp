#include<bits/stdc++.h>
using namespace std;
const int n=1e7;
int main()
{
    long long int n, k;
    cin>>n>>k;
    int arr[n];
    for(long long int i=0;i<(n/2);i++)
    {
        arr[i]=(2*i)+1;
    }
    if(n%2==0)
    {
    for(long long int i=n/2,j=1;i<n,j<=n/2;i++,j++)
    {
        arr[i]=2*j;
    }
    }
    else
    {
    for(long long int i=(n/2)+1,j=1;i<n,j<=n/2;i++,j++)
    {
        arr[i]=2*j;
    }
    }
    cout<<arr[k-1];
    return 0;
}