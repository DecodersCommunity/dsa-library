#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (1)
    {
        int n;
        cin >> n;
        if (n == -1)
            break;
        int arr[n];
        int load = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            load += arr[i];
        }
        if (load % n != 0)
        {
            cout << -1 << "\n";
            continue;
        }
        load = load / n;
        int diff = 0;
        int maxLoad = INT_MIN;
        // Partition Step:
        for (int i = 0; i < n; i++)
        {
            diff += (arr[i] - load);
            maxLoad = max(maxLoad, abs(diff));
        }
        cout << maxLoad << "\n";
    }
    return 0;
}