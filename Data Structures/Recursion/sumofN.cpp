#include <bits/stdc++.h>
using namespace std;

int sumNum(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    // recursive call
    // if (n != 0)
    // {

    //     return n + sumNum(n - 1);
    // }
    return n + sumNum(n - 1);
}

int main()
{

    int n;
    cout << "Enter the Number : ";
    cin >> n;
    cout << "Sum =  " << sumNum(n);
    return 0;
}