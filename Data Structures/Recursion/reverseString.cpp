#include <bits/stdc++.h>
using namespace std;

int reverseString(string &str, int i, int j)
{
    cout << "Call : " << str << endl;

    // Base Case
    if (i > j)
    {
        return true;
    }
    swap(str[i++], str[j--]);
    // recursive call
    reverseString(str, i, j);
}

int main()
{
    string str = "bhavesh";
    cout << endl;
    // n = strlen(str);
    reverseString(str, 0, str.length() - 1);
    cout << "Reversed String : " << str << endl;
    cout << endl;
    return 0;
}
