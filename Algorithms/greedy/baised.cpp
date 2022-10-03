#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<string, ll> psl;

static bool compare(psl &a, psl &b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<psl> v;
        for (ll i = 0; i < n; i++)
        {
            string s;
            ll r;
            cin >> s >> r;
            v.push_back({s, r});
        }
        sort(v.begin(), v.end(), compare);
        ll badness = 0;
        for (ll i = 0; i < n; i++)
        {
            badness += abs(v[i].second - (i + 1));
        }
        cout << badness << "\n";
    }
    return 0;
}
