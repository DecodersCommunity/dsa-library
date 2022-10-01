#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int dp[x+1][y+1];
        
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }

    int lps(string s1){
        int n=s1.size();
        string s2=s1;
        reverse(s1.begin(),s1.end());
        return lcs(n,n,s1,s2);
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        cin>>s1;        // Take both the string as input
        Solution ob;
        cout << ob.lps(s1) << endl;
    }
    return 0;
}
  // } Driver Code Ends