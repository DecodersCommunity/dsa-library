#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int>& arr){
  
   for(int i=1; i<arr.size(); i++){
   int  key=arr[i];
    int j= i-1;
   while( j>=0 && arr[j]>key){
    arr[j+1]=arr[j];
    j--;
    }
arr[j+1]=key;
}
for(int ele: arr){
    cout<<ele<<" ";
}
}
int main(){
    vector<int>arr={30,20,10,76,8,87,45,65,67,2,4,5,45,6};
insertionsort(arr);
    return 0;
}
