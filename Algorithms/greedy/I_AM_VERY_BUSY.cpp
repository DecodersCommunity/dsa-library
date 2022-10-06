#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

static bool compare(pi &a, pi &b)
{
    return (a.second < b.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pi> act(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            act[i] = {x, y};
        }
        sort(act.begin(), act.end(), compare);
        int ans = 1;
        int limit = act[0].second;
        for (int i = 1; i < n; i++)
        {
            if (act[i].first >= limit)
            {
                limit = act[i].second;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}