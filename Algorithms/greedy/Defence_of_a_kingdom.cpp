#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int w, h, t;
        cin >> w >> h >> t;
        vector<int> x(t, 0);
        vector<int> y(t, 0);
        for (int i = 0; i < t; i++)
        {
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int xMax = x[0] - 1, yMax = y[0] - 1;
        for (int i = 1; i < t; i++)
        {
            xMax = max(xMax, x[i] - x[i - 1] - 1);
            yMax = max(yMax, y[i] - y[i - 1] - 1);
        }
        // Corner case:
        xMax = max(xMax, w - x[t - 1]);
        yMax = max(yMax, h - y[t - 1]);
        cout << xMax * yMax << "\n";
    }
    return 0;
}