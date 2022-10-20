Nitin Kumar <200104042@hbtu.ac.in>


#include <bits/stdc++.h>
using namespace std;

int eulerian(int n, int m)
{
	if (m >= n || n == 0)
		return 0;

	if (m == 0)
		return 1;

	return (n - m) * eulerian(n - 1, m - 1) +
		(m + 1) * eulerian(n - 1, m);
}
int main()
{
	int n = 3, m = 1;
	cout << eulerian(n, m) << endl;
	return 0;
}
