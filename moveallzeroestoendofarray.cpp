// Ameyanshu Mishra <ameyanshumishra@gmail.com>
#include <stdio.h>

// Function which pushes all zeros to end of an array.
void pushZerosToEnd(int arr[], int n)
{
	int count = {0}; // Count of non-zero elements

	// Traverse the array. If element encountered is non-
	// zero, then replace the element at index 'count'
	// with this element
	for (int i = 0; i < n; i++)
		if (arr[i] != 0)
			arr[count++] = arr[i]; // here count is
								// incremented

	// Now all non-zero elements have been shifted to
	// front and 'count' is set as index of first 0.
	// Make all elements 0 from count to end.
	while (count < n)
		arr[count++] = 0;
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	pushZerosToEnd(arr, n);
	printf("%s\n", "Array after pushing all zeros to end of array:");
	for (int i = 0; i < n; i++)
	printf("%d ", arr[i]);
	return 0;
}
