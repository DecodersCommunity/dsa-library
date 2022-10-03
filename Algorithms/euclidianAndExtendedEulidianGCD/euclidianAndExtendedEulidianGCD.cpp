#include <bits/stdc++.h>
using namespace std;

#define int            long long int
#define ff              first
#define ss              second
#define pb             push_back
#define py             cout<<"YES\n"
#define pn             cout<<"NO\n"
#define pm                cout<<"-1\n";
#define pimp           cout<<"IMPOSSIBLE\n";
#define rep(i,n)       for (int i = 0;i < n;i++)
#define repi(i,x,n)    for (int i = x;i < n;i++)
#define repl(i,n,x)    for (int i = n; i >= x; i--)
#define spi            set <pii>
#define endl           "\n"
#define gcd            __gcd
#define pi             3.141592653589793238
#define rall(p)        p.end() , p.begin()
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.ff << " " << x.ss << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

int lcm(int a,int b) {return (a/gcd(a,b)*b);}
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return a.ss < b.ss;}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return a.ss > b.ss;}

string decToBinary(int n){
    string s="";int i=0;while(n>0){s = to_string(n % 2)+ s; n /= 2;i++;}
    return s;}

int binaryToDecimal(string n){
    string num = n;int dec_value = 0;int base = 1;int len = num.length();
    for(int i = len - 1; i >= 0; i--){
    if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

bool isPrime(int n) {
    if(n <= 1)return false; if(n<=3)return true; if(n%2==0||n%3==0)return false;
    for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}

bool isPerfectSquare(int x){if (x >= 0) {int sr = sqrt(x);return (sr * sr == x);}
    return false; }

bool isPowerOfTwo(int n){
    if(n==0)return false;
    return (ceil(log2(n)) == floor(log2(n)));}

inline int power(int a, int b) {
    int x = 1;
    while (b) {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

const int N = 1e9 + 7;
const int INF = LONG_LONG_MAX;
// O(log(min(a,b))
int gcd(int a,int b) {
    if(!b) return a;
    return gcd(b,a%b);
}
// vector will return X , Y and gcd(a,b)
// A % B = A - floor(A/B)*B
vector<int> extendedEulidianGCD(int a,int b) {
    if(!b) return {1,0,a};
    vector<int> result = extendedEulidianGCD(b,a%b);
    // bottom up solution building as operations after recurrsion call
    int smallX = result[0],smallY = result[1];

    int x = smallY, y = smallX - (a/b)*smallY,GCD = result[2];

    return {x,y,GCD};
}

void solve() {
    int a,b; cin>>a>>b;
    cout<<gcd(a,b)<<endl;

    // extended eulidian algo => ax + by = gcd(a,b) find x and y and also for GCD
    vector<int> ans = extendedEulidianGCD(a,b);

    cout<<"X: "<<ans[0]<<"|"<<"Y: "<<ans[1]<<endl;
    cout<<"GCD: "<<ans[2]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    clock_t z = clock();

    int t = 1,i = 1;
    // cin >> t;
    while (t--){
          // cout<<"Case #"<<i++<<": ";
          solve();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}