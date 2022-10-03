//contributed by - HARSH AGARWAL <harsh5nov11@gmail.com>

#include <iostream>
#include<conio.h>

using namespace std;
 
int main() {

	// Declare Array Variable
    int array[5]= { 1, 2, 3, 4, 5 };
    
    //Read Day Value
	int size;
	
	cout<<"Simple C++ Example Program for Simple C++ Program for Find Array Size\n";
	
	size = sizeof(array)/sizeof(int);

    //Print size of Array
    cout<<"The Size of Array is "<<size;
    
   getch();
	return 0;
}
