// CPP program to count number of subsequences
// which when multiplied result in a power of 2.
#include <bits/stdc++.h>
using namespace std;

// Function to check if num is power of
// two or not.
bool isPowerOf2(int num)
{
	if (num == 0)
		return false;

	if (num == 1)
		return true;

	if (num & (num - 1))
		return false;

	return true;
}

// counting all subsequences whose product
// is power of 2.
int countSubsequence(int a[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (isPowerOf2(a[i]))
			count++;
	return (int)(pow(2, count)) - 1;
}

// Driver code
int main()
{
	int a[] = { 1, 2, 3 };
	cout << countSubsequence(a, 3) << endl;
	int b[] = { 3, 5, 9 };
	cout << countSubsequence(b, 3) << endl;
	return 0;
}
