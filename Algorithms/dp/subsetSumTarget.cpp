#include <bits/stdc++.h>
using namespace std;

bool target(int n,int sum,int arr[]){

	bool dp[n+1][sum+1];
	for(int i=0;i<=n;i++) dp[i][0]=true;
	for(int i=0;i<=sum;i++) dp[0][i]=false;

	for(int i=1;i<=n;i++){
           for(int j=1;j<=sum;j++){
               if(arr[i-1]<=j){
                   dp[i][j]=((dp[i-1][j-arr[i-1]]) || (dp[i-1][j]));
               }
               else if(arr[i-1]>j){
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
	   return dp[n][sum];
}

int main(){

	int n,sum;
	cin>>n>>sum;

	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	if(target(n,sum,arr)) cout<<"Yes";
	else cout<<"No";

	return 0;
}

//A variation of 0 1 Knapsack Problem. 