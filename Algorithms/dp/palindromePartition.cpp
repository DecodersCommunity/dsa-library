// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string& str, int i ,int j)
    {
        
        while(i<j)
        {
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& str, int i , int j)
    {
        if(i>=j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(isPalindrome(str,i,j) == true)
        {
            dp[i][j] = 0;
            return 0;
        }
        
        
        int ans = INT_MAX;
        
        for(int k = i; k<=j-1; k++)
        {
            int right = 0;
            if(isPalindrome(str,i,k)){
                right = solve(str,k+1,j); //Only solve 1 recursive call //optimising dp solution.
            }
            else{
                dp[i][k] = 0;
                continue;
            }
            
            int temp = right+1;
            ans = min(temp, ans);
        }
        
        return dp[i][j] = ans;
    }
    int palindromicPartition(string s) {
         int n = s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(s,0,s.size()-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends