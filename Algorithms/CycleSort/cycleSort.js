// Contributed by - Mansi Purwar <purwarmansi9@gmail.com>
  <script>
// Javascript program to implement cycle sort

	// Function sort the array using Cycle sort
	function cycleSort(arr, n)
	{
	
		// count number of memory writes
		let writes = 0;

		// traverse array elements and put it to on
		// the right place
		for (let cycle_start = 0; cycle_start <= n - 2; cycle_start++)
		{
		
			// initialize item as starting point
			let item = arr[cycle_start];

			// Find position where we put the item. We basically
			// count all smaller elements on right side of item.
			let pos = cycle_start;
			for (let i = cycle_start + 1; i < n; i++)
				if (arr[i] < item)
					pos++;

			// If item is already in correct position
			if (pos == cycle_start)
				continue;

			// ignore all duplicate elements
			while (item == arr[pos])
				pos += 1;

			// put the item to it's right position
			if (pos != cycle_start)
			{
				let temp = item;
				item = arr[pos];
				arr[pos] = temp;
				writes++;
			}

			// Rotate rest of the cycle
			while (pos != cycle_start)
			{
				pos = cycle_start;

				// Find position where we put the element
				for (let i = cycle_start + 1; i < n; i++)
					if (arr[i] < item)
						pos += 1;

				// ignore all duplicate elements
				while (item == arr[pos])
					pos += 1;

				// put the item to it's right position
				if (item != arr[pos]) {
					let temp = item;
					item = arr[pos];
					arr[pos] = temp;
					writes++;
				}
			}
		}
	}
	
// Driver code

	let arr = [ 1, 8, 3, 9, 10, 10, 2, 4 ];
	let n = arr.length;
	cycleSort(arr, n);

	document.write("After sort : " + "<br/>");
	for (let i = 0; i < n; i++)
		document.write(arr[i] + " ");

// This code is contributed by susmitakundugoaldanga.
</script>
