// Contributed by - Shlok Kumar Suman <shloksuman01@gmail.com>

#include<bits/stdc++.h>
using namespace std;

void createArr(int arr[], int size){
    cout << "Enter the elements of the array : " ;
    for(int i=0 ; i<size ; i++){
        cin >> arr[i] ;                
    }
}

//PRINTING ARRAY
void printarray(int arr[], int size) {
    cout << "The array is : " ;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl ;        
    }  
}

int kadane(int arr[] , int size){       //🆃🅸🅼🅴 🅲🅾🅼🅿🅻🅴🆇🅸🆃🆈 🅾(🅽)
    int ans = INT_MIN;
    int maxTillnow = 0;

    for(int i=0;i<size;i++){
    
    maxTillnow= maxTillnow + arr[i] ;

    ans = max(maxTillnow, ans) ;

    if(maxTillnow<0){
        maxTillnow=0;
    }

    }

    return ans;
}
void kadaneSubArray(int arr[] , int size){       //🆃🅸🅼🅴 🅲🅾🅼🅿🅻🅴🆇🅸🆃🆈 🅾(🅽)
    int ans = INT_MIN;
    int maxTillnow = 0;
    int start=0;
    int end;

    cout << "The largest subarray using KADANE'S ALGO IS : " ;

    for(int i=0;i<size;i++){
    
    maxTillnow= maxTillnow + arr[i] ;

    end = i;

    ans = max(maxTillnow, ans) ;

    if(maxTillnow<0){
        maxTillnow=0;
        start=i+1;
    }

    }

    for(int k=start ; k<=end; k++){
        cout << arr[k] << " " ;
    }

    
}

int main(){

    int arr[100];
    cout << "Enter the size of element : " ;
    int size;
    cin>>size;
    createArr(arr,size);
    cout<< "The max subarray sum is : " << kadane(arr,size) << endl;
    kadaneSubArray(arr,size) ; //prints the subarray that makes up the largest sum
    

return 0;
}
