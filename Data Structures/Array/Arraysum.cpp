#include <iostream>
using namespace std;

int sum=0;

void SumArray(int arr[],int n){

    cout << "Sum Of All Elements of Array" <<endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        sum = sum + arr[i];
        
    } 
    cout << endl;  
}

//Sum Of Elements

int main()
{
    int n=15;
    int harsh[15]={1,2,3,4,5,6,7,8,9};
    SumArray(harsh,15);
    cout << "Sum is:" << sum <<endl;

return 0;

}

