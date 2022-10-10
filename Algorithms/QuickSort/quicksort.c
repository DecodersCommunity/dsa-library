// Contributed by Srijani Guha Ray <srijani.guharay@gmail.com>
// Quick sort in C

#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int arr[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = arr[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&arr[i], &arr[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&arr[i + 1], &arr[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(arr, low, high);
    
    // recursive call on the left of pivot
    quickSort(arr, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(arr, pi + 1, high);
  }
}

// function to print array elements
void print(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}

// main function
int main() {
  int arr[100],n,i;
  //taking input of array size
  printf("Enter the size of the array:");
  scanf("%d",&n);
  printf("Enter the array:");
  for(i=0;i<n;i++)
  {
      scanf("%d",&arr[i]);
  }
  printf("Unsorted Array is:\n");
  print(arr, n);
  
  // perform quicksort on data
  quickSort(arr, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  print(arr, n);
}
