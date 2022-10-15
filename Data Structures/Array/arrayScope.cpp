#include <iostream>
using namespace std;

void update(int arr[],int n){

    cout << endl <<"Inside the Function" <<endl;

    //updating the array first element

    arr[0]=120;

    //printing the main function
    for (int i = 0; i < 3; i++)
    {
        cout<< arr[i] << " ";
    }

    cout<<endl;


    cout<<"Going Back to Main Function" <<endl;


}

int main(){

    int arr[3]={1,2,3};

    update(arr,3);
    for (int i = 0; i < 3; i++)
    {
        cout<< arr[i] << " ";
    }
    

}