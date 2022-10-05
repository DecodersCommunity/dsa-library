// Contributed By- Pranjal Mishra <pranjalreemamishra@gmail.com>

// C++ implementation to find
// square root of given number
// upto given precision using
// binary search.

#include <bits/stdc++.h>
using namespace std;

// Function to find square root
// of given number upto given
// precision
float squareRoot(int number, int precision)
{
	int start = 0, end = number;
	int mid;

	// variable to store the answer
	float ans;

	// for computing integral part
	// of square root of number
	
	while (start <= end) {
		mid = (start + end) / 2;
		// checking if integral part lies on the mid
		if (mid * mid == number) {
			ans = mid;
			break;
		}

		// incrementing start if integral
		// part lies on right side of the mid
		if (mid * mid < number) {
			start = mid + 1;
			ans = mid;
		}

		// decrementing end if integral part
		// lies on the left side of the mid
		else {
			end = mid - 1;
		}
	}

	// For computing the fractional part
	// of square root upto given precision
	float increment = 0.1;
	for (int i = 0; i < precision; i++) {
		while (ans * ans <= number) {
			ans += increment;
		}

		// loop terminates when ans * ans > number
		ans = ans - increment;
		increment = increment / 10;
	}
	return ans;
}

// Driver code
int main()
{
    
	// Function calling
	// square root of 50 upto 3rd precision
	cout << squareRoot(50, 3) << endl;

	// Function calling
	cout << squareRoot(10, 4) << endl;

	return 0;
}
