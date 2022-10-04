#include<bits/stdc++.h>
using namespace std;

int PrintingSubArray(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<",";
            }
            cout<<endl;
            
        }
        
    }
}

int SubArraySumBruteForce(int *arr,int n){
    int largest_sum = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int SubArraySum =0;
            for(int k=i;k<=j;k++){
                SubArraySum+=arr[k];
            }
            largest_sum = max(largest_sum,SubArraySum);
        }
    }
    cout<< largest_sum;
}


int SubArraySumPrefixSum(int *a,int n){
    int largest_sum = 0;  
    //Prefix Array 
    int prefix[100] = {0};
    //intializing array as a[0] prefix sum would be the same a[0]
    prefix[0] = a[0];
    //starting from index 1 as prefixsum[0] =a[0]
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int SubArraySum= i>0? prefix[j]-prefix[i-1]: prefix[j];
            // int SubArraySum;
            // i>0? SubArraySum=prefix[j]-prefix[i-1]: SubArraySum =prefix[j];
            largest_sum = max(largest_sum,SubArraySum);

        }

    }
    cout<< largest_sum<<endl;

}


int SubArraySumKadaneAlgo(int a[],int n){
    //current sum 
    int cs=0;
    int largest =0;

    for(int i=0;i<n;i++){
        cs+=a[i];
        if(cs<0){
            cs=0;
        }
        largest =max(largest,cs);
    }
    cout<<cs;
}


int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    PrintingSubArray(arr,n);
    cout<<endl;
    SubArraySumBruteForce(arr,n);
    cout<<endl;
    SubArraySumPrefixSum(arr,n);
    SubArraySumKadaneAlgo(arr,n);
}
