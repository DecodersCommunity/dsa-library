//Given n steps and max jumps = k . Find no of ways to reach the top.

#include <bits/stdc++.h>
using namespace std;

int ladders(int n,int k,int dp[]){

    //Top down dp:

    if(n==0) return 1; //i.e we are at the ground level. So 1 way to reach the top.

    if(dp[n]!=0) return dp[n];

    int ways=0;
    for(int i=1;i<=k;i++){
        if((n-i)>=0){
            ways+=ladders(n-i,k,dp);
        }
    }

    return dp[n]=ways;
}

int main(){

    int n,k;
    cin>>n>>k;
    int dp[100]={0};

    cout<<ladders(n,k,dp)<<endl;

    return 0;
}