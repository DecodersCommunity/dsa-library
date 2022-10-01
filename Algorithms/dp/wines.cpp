#include <bits/stdc++.h>
using namespace std;

int maxProfit(int p[],int i,int j,int y,int dp[][100]){

    //Base Case:
    //If (i>j) no bottles are left. Hence,profit is 0.
    if(i>j) return 0;

    //Lookup case:
    if(dp[i][j]!=0) return dp[i][j];

    //Recursive Case:
    int op1= p[i]*y + maxProfit(p,i+1,j,y+1,dp);
    int op2= p[j]*y + maxProfit(p,i,j-1,y+1,dp);
    return dp[i][j] = max(op1,op2);
}

int main(){

    int p[]={2,3,5,1,4};
    int dp[100][100]={0}; //2D array for dp
    int n = sizeof(p)/sizeof(int);
    int y=1;
    cout<<maxProfit(p,0,n-1,y,dp)<<endl;

    return 0;
}