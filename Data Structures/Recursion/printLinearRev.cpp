#include <bits/stdc++.h>
using namespace std;

void printLinearly(int n)
{
    // cout<<"N : "<<n;
    // cout<<endl;
    // base case
    if (n == 0)
    {
        return;
    }
    
    // recursive call
     cout << n<<" ";
    printLinearly(n - 1);
   
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    printLinearly(n);
}