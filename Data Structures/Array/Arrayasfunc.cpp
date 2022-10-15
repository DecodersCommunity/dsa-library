#include <iostream>
using namespace std;

void printArray(char arr[], int size){

    cout << "printing the array" << endl;
    //print the array
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Printing Done" << endl;
    
}

int main(){
    
int third[15]= {2,7};

int n = 15;
printArray(third, 15);

int thirdSize = sizeof(third)/sizeof(int);
cout<<"Size of third is" << thirdSize <<endl;

char ch[5] = {'a','b','c','d','e'};
cout << ch[3] << endl;

printArray(ch);

}
