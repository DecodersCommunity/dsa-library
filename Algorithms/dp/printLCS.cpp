#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    string lcs(int x, int y, string s1, string s2)
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
        int i=x,j=y;
        string str="";
        while(i>0 and j>0){
            if(s1[i-1]==s2[j-1]){
                str.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1]<dp[i-1][j]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends