#include <iostream>
using namespace std;

int F(){
    cout<<"1";
    F();
}



int main(){
    cout<<F();
    return 0;

}