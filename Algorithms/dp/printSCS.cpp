#include<bits/stdc++.h>
using namespace std;

void print(string a,string b,int m, int n)
{
    int t[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
        }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    int i=m,j=n; string s="";
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            s.push_back(a[i-1]);
            i--;
            j--;
        }

        if(t[i][j-1]>t[i-1][j])
        {

            s.push_back(b[j-1]);
            j--;
        }
        else{
            s.push_back(a[i-1]);
            i--;
        }
    }
    while(i>0)
    {
        s.push_back(a[i-1]);
        i--;
    }

    while(j>0)
    {
        s.push_back(b[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}


int main()
{
    string a="aggtab";
    string b="gxtxayb";
    int m=a.size();
    int n=b.size();
    print(a,b,m,n);

    return 0;
}