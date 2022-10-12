#include<iostream>
using namespace std;
int pivote_element(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }

        mid = (s + e) / 2;
    }
    return s;
}

int binary_search(int arr[], int n,int m, int key)
{
    int s = n;
    int e = m- 1;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {

            return mid;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return -1;
}

int main(){
                int n;
                cout<<"Enter the number of element in array"<<endl;
                cin>>n;
                int arr[n];
                cout<<"Enter elements of array"<<endl;
                for(int i=0; i<n;i++){
                    cin>>arr[i];
                }
                int key;
                cout<<"Enter the element which you want to find in array"<<endl;
                cin>>key;
                 int a=pivote_element(arr,n);
                 
    if (key > arr[a] && key>=arr[0])
    {
        cout << "Element find at index: " << binary_search(arr,0, a, key);
    }
    else {
        cout<<"Element find at  index: "<<binary_search(arr,a,n,key);
    }
            
return 0;
}
