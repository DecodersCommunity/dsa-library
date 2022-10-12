// Contributed by - Abhay Singh Verma <abhaysinghverma@gmail.com>
<script>
// Javascript program to implement Jump Search

function jumpSearch(arr, x, n)
{
	// Finding block size to be jumped
	let step = Math.sqrt(n);

	// Finding the block where element is
	// present (if it is present)
	let prev = 0;
	while (arr[Math.min(step, n)-1] < x)
	{
		prev = step;
		step += Math.sqrt(n);
		if (prev >= n)
			return -1;
	}

	// Doing a linear search for x in block
	// beginning with prev.
	while (arr[prev] < x)
	{
		prev++;

		// If we reached next block or end of
		// array, element is not present.
		if (prev == Math.min(step, n))
			return -1;
	}
	// If element is found
	if (arr[prev] == x)
		return prev;

	return -1;
}

// Driver program to test function
let arr = [0, 1, 1, 2, 3, 5, 8, 13, 21,
				34, 55, 89, 144, 233, 377, 610];
let x = 55;
let n = arr.length;
	
// Find the index of 'x' using Jump Search
let index = jumpSearch(arr, x, n);

// Print the index where 'x' is located
document.write(`Number ${x} is at index ${index}`);

// This code is contributed by _saurabh_jaiswal
</script>
