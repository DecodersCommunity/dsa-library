#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    // base case
    if (n == 0)
    {
        return;
    }

    // processing case
    int digit = n % 10;
    n = n / 10;

    // recursive call
    sayDigit(n, arr);
    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    int n;
    cout << "Enter a Number : ";
    cin >> n;
    sayDigit(n, arr);

    return 0;
}