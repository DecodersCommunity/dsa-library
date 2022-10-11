#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    // base case
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = power(a, b / 2);
    if (b % 2 == 0)
    // even
    {
        return ans * ans;
    }
    else
    {
        // odd
        return ans * ans * a;
    }
}

int main()
{
    int a, b;
    cout << "Enter value of Base : ";
    cin >> a;
    cout << "Enter value of Power : ";
    cin >> b;

    int ans = pow(a, b);
    cout << "Answer : " << ans << endl;
}