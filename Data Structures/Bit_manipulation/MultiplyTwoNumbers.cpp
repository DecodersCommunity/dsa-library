// CPP program to find multiplication
// of two number without use of
// multiplication operator
#include<bits/stdc++.h>
using namespace std;
 
// Function for multiplication
int multiply(int n, int m)
{ 
    int ans = 0, count = 0;
    while (m)
    {
        // check for set bit and left
        // shift n, count times
        if (m % 2 == 1)             
            ans += n << count;
 
        // increment of place value (count)
        count++;
        m /= 2;
    }
    return ans;
}
 
// Driver code
int main()
{
    int n = 20 , m = 13;
    cout << multiply(n, m);
    return 0;
}