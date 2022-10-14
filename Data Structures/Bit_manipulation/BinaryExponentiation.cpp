// Contributed by - Ali Saquib Raza <razaalisaquib69@gmail.com>
// Compute x^n mod m
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
#include <iostream>

using namespace std;

int main()
{
    long long a,b;
    cin>>a>>b;
    long long result = binpow(a,b);
    cout<<result<<endl;
    return 0;
}
