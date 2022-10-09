/* Java program to implement Pigeonhole Sort */

import java.lang.*;
import java.util.*;

class pigeon
{
	public static void pigeonhole_sort(int arr[],
										int n)
	{
		int min = arr[0];
		int max = arr[0];
		int range, i, j, index;

		for(int a=0; a<n; a++)
		{
			if(arr[a] > max)
				max = arr[a];
			if(arr[a] < min)
				min = arr[a];
		}

		range = max - min + 1;
		int[] phole = new int[range];
		Arrays.fill(phole, 0);

		for(i = 0; i<n; i++)
			phole[arr[i] - min]++;

		
		index = 0;

		for(j = 0; j<range; j++)
			while(phole[j]-->0)
				arr[index++]=j+min;

	}

	public static void main(String[] args)
	{
		pigeon sort = new pigeon();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter size of array:");
		int n=sc.nextInt();
    int[] arr = new int[n];
    System.out.println("Enter the elements of array:" );
    for(int i=0;i<n;i++)
    {
        arr[i]=sc.nextInt();
    }

		System.out.print("Sorted order is : ");

		sort.pigeonhole_sort(arr,arr.length);
		
		for(int i=0 ; i<arr.length ; i++)
			System.out.print(arr[i] + " ");
	}

}


