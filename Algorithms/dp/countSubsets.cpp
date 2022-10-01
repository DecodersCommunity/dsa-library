#include <bits/stdc++.h>
using namespace std;

int count(int n,int sum,int a[]){

    int dp[n+1][sum+1]; //DP Array

    //Initialisation
    dp[0][0]=1;
    for(int i=1;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=sum;i++) dp[0][i]=0;

    //Logic case
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-a[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

        return dp[n][sum]; //Ans
}

int main(){

    int n = 6;
    int a[] = {2,3,5,6,8,10};
    int sum = 10;

    cout<<count(n,sum,a)<<endl;

    return 0;
}