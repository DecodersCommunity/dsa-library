// Contributed by - Rajat Rathore <rajat12350iam@gmail.com>

#include<iostream>
using namespace std;

void printArr(int arr1[],int n){
  for(int i=0; i<n; i++){
    cout << arr1[i] << " ";
  }
}
void merge(int arr1[],int mid, int low,int high){
  int i,j,k;
  int arr2[high+1];
  i=low;
  j= mid + 1;
  k=low;

  while(i<=mid && j<=high){
    if(arr1[i]<arr1[j]){
      arr2[k]= arr1[i];
      i++;
      k++;
    }
    else{
      arr2[k]= arr1[j];
      j++;
      k++;
    }
  }
  while(i<=mid){
    arr2[k]=arr1[i];
    i++;
    k++;
  }
  while(j<=high){
    arr2[j]= arr1[j];
    j++;
    k++;
  }
  for(int i=low; i<=high; i++){
    arr1[i] = arr2[i];
  }
}
void mergeSort(int arr1[],int low,int high){
  if(low<high){
    int mid = (low+high)/2;
    mergeSort(arr1,low,mid);
    mergeSort(arr1,mid+1,high);
    merge(arr1,mid,low,high); // merging each element in sorted order
  }
}

int main(){
  int n;
  cin >> n;
  int arr1[n];
  for(int i=0; i<n; i++){
    cin >> arr1[i];
  }
  mergeSort(arr1,0,n-1);
  cout << "Sorted array-" << " " ;
  printArr(arr1,n);
}