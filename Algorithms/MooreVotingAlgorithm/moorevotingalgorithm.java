// Contributed by - Saksham Kankani<superherosaksham@gmail.com>

// Moore Voting Algorithm
//Time Complexity=O(N)
//Space Complexity=O(1)

import java.util.*;
import java.io.*;

class MooreVoting
{

// Function to find majority element
public static int Majority(int[] ar)
{
	int c = 0, 
  int candidate = -1;

	// Finding majority candidate
	for (int i= 0; i < ar.length; i++) {
	if (c == 0) {
		candidate = ar[i];
		c = 1;
	}
	else {
		if (ar[i] == candidate)
		c++;
		else
		c--;
	}
	}

	// Checking if majority candidate occurs more than
	// n/2 times
	c = 0;
	for (int i = 0; i < ar.length; i++) {
	if (ar[i] == candidate)
		c++;
	}
	if (c > (ar.length / 2))
	return candidate;
	return -1;

}

// Main
public static void main(String[] args)
{
	int ar1[] = { 3,3,5,5,5,6,7};
	int major = Majority(ar1);
	System.out.println(" The majority element is : " + major);
}
}
