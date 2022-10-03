// contributed by- HARSH AGARWAL <harsh5nov11@gmail.com>

#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse a string
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
 
int main()
{
    string str;
    cin>> str;
    reverseStr(str);
    cout << str;
    return 0;
}
