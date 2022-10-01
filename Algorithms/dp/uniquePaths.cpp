//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
   public:
   //Function to find total number of unique paths.
   int NumberOfPath(int m, int n)
   {

    int path[m][n];
    for(int i=0;i<n;i++)
    path[0][i]=1;
    for(int i=0;i<m;i++)
    path[i][0]=1;
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            path[i][j]=path[i-1][j]+path[i][j-1];
        }
    }
    return path[m-1][n-1];}
};
 


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends