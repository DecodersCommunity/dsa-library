#include <bits/stdc++.h>
using namespace std;

void printLinearly(int n)
{
    cout<<"N : "<<n;
    cout<<endl;
    // base case
    if (n == 0)
    {
        return;
    }
    
    // recursive call
    printLinearly(n - 1);
    cout << n<<" ";
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    printLinearly(n);
}