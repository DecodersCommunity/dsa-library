// Leaders in an Array

//An element is a leader if it is greater than all the elements to its right side.
// And the rightmost element is always a leader. 

#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

class Solution
{
    public:
    vector<int> leaders(int a[],int n)
    {
        //Code Here
        vector<int> lead;
        int m = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>=m)
                lead.push_back(a[i]);
            m = max(m,a[i]);
        }
        int low = 0, high = lead.size()-1;
        while(low<high){
           int temp = lead[low];
           lead[low] = lead[high];
           lead[high] = temp;
           low++;
           high--;
       }
       return lead;
    }
    
};

int main()
{
    int arr[]={16,17,4,3,5,2};
    int n=6;
    Solution obj;
    vector <int> v=obj.leaders(arr,n);

    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}