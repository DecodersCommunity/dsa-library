#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lol n, d;
    cin >> n >> d;
    lol a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    lol ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] <= d)
        {
            ans++;
            i++;
        }
    }
    cout << ans << "\n";
    return 0;
}