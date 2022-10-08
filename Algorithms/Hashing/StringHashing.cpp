// Contributed by - Ali Saquib Raza <razaalisaquib69@gmail.com>
/*Search for duplicate strings in an array of strings*/
#include <bits/stdc++.h>
using namespace std;
int compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    int hash_value = 0;
    int p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
int main()
{
    vector<string> v{"ali","ali","dog","girl","dog"};
    vector<vector<int>> res = group_identical_strings(v);
    for(auto i : res){
        for(auto r : i){
            cout<<r<<" ";
        }
        cout<<endl;
    }
    return 0;
}
