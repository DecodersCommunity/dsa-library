//Anmol Krishna <krishnaansu12@gmail.com>
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

// Returns Factorial of N
ull factorial(int N)
{

	// Initialize result
	ull f = 1; // Or BigInt 1

	// Multiply f with 2, 3, ...N
	for (ull i = 2; i <= N; i++)
		f *= i;

	return f;
}

// Driver method
int main()
{
	int N = 20;
	cout << factorial(N) << endl;
}

// This code is contributed by phasing17
