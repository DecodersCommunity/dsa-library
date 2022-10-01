#include <bits/stdc++.h>
using namespace std;

//Top down (Recursive)

int stepsT(int n,int dp[]){
    //Base case:
    if(n==1) return 0; //If num is 1 then we take 0 steps.

    //Lookup in dp array:
    if(dp[n]!=0){
        return dp[n];
    }

    //Recursive case:
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;
    //We have to choose bw the three options
    if(n%3==0) op1=stepsT(n/3,dp);
    if(n%2==0) op2=stepsT(n/2,dp);
    op3=stepsT(n-1,dp);

    int ans = min(min(op1,op2),op3) + 1;
    return dp[n]=ans;
}

//Bottom up approach (Iterative)

int stepsBU(int n){
    int dp[1000]={0};
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(n%3==0) op1=dp[i/3];
        if(n%2==0) op2=dp[i/2];
        op3=dp[i-1];
        dp[i] = min(min(op1,op2),op3) + 1;
    }
    return dp[n];
}

int main(){

    int n;
    cin>>n;
    int dp[1000]={0};
    cout<<stepsT(n,dp)<<endl;
    cout<<stepsBU(n)<<endl;

    return 0;
}