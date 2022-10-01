//Matrix chain Multiplication

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mcm(int arr[], int n, int i, int j, vector<vector<int>> &dp)
    {
        if(i >= j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MAX, cost;
        
        for(int k = i; k < j; k++)
        {
            cost = mcm(arr, n, i, k, dp) + mcm(arr, n, k+1, j, dp) + arr[i] * arr[k+1] * arr[j+1];
            ans = min(ans, cost);
        }
        
        dp[i][j] = ans;
        return ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1, vector<int> (N+1, -1));
        return mcm(arr, N, 0, N-2, dp);
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends