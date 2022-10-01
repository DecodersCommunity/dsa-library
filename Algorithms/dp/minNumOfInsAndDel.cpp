#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int lcs(string x,string y,int m,int n){
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    int lenLcs = lcs(str1,str2,m,n);
	    int del = m-lenLcs;
	    int ins = n-lenLcs;
	    return del+ins;
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends