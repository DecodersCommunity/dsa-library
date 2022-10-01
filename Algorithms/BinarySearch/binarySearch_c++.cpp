#include<iostream>
using namespace std;

//array must be sorted in non deceasing order
// In this algorithm we divide our array in two parts until we find our required value
// Its time comlexity is O(logn)

bool Bsearch(int A[], int S , int L, int x){
    if(L == 1)  return A[S] == x;
    int H = L/2;
    if(x < A[S+H]){
        return Bsearch(A,S,H,x);
    }
    else{
        Bsearch(A,S+H,L-H,x);
    }
}

int main(){
    int A[8] = {-1,2,2,4,10,12,30,30};
    cout << Bsearch(A,0,8,10) << endl;
}