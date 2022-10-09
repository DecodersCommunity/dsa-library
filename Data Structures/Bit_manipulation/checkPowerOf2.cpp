// Contributed by - Ali Saquib Raza <razaalisaquib69@gmail.com>
//to check if the given number is a power of two
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(!(n&(n-1))){
        cout<<"The number is a power of 2";
    }else{
        cout<<"The number is not a power of 2";
    }
    return 0;
}
