#include <bits/stdc++.h>
using namespace std;
bool palindrome(string str, int start, int end)
{
    // Base Case
    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    // Recursive Case
    palindrome(str, start + 1, end - 1);
}

int main()
{
    char str[] = "malayalam";
    int n = strlen(str);
    int ans = palindrome(str, 0, n - 1);
    if (ans)
    {
        cout << "String is Palindrome" << endl;
    }
    else
    {
        cout << "String is not Palindrome" << endl;
    }
    return 0;
}