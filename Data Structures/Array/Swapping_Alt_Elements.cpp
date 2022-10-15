#include <iostream>
using namespace std;

void PrintArray(int arr[],int size){

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

void swapAlternate(int arr[], int size){

    for (int i = 0; i < size; i+=2)
    {
        if (i<size)
        {
            swap(arr[1],arr[i+1]);
        }
        
    }
}

int main(){

    int even[8]={5,2,8,6,1,0,6,82};
    int odd[5]={11,33,55,77,9};

    swapAlternate(even,8);
    PrintArray(even,8);

    cout <<endl;

    swapAlternate(odd,6);
    PrintArray(odd,6);

    return 0;
}