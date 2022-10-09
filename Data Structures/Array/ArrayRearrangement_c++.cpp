

#include <bits/stdc++.h>
using namespace std;


void rearrangeArr(int arr[], int n)
{
	
	int evenPos = n / 2;
	
	int oddPos = n - evenPos;
	int tempArr[n];

	
	for (int i = 0; i < n; i++)
		tempArr[i] = arr[i];

	
	sort(tempArr, tempArr + n);
	int j = oddPos - 1;

	
	for (int i = 0; i < n; i += 2)
		arr[i] = tempArr[j--];

	j = oddPos;

	
	for (int i = 1; i < n; i += 2)
		arr[i] = tempArr[j++];

	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	rearrangeArr(arr, size);
	return 0;
}
