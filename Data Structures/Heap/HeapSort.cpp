//Contributed By : Ankit Srivastava <ankit1998sri@gmail.com>
#include <bits/stdc++.h>
using namespace std;
void downheapify(vector<int > &heap, int idx){
    int left=2*idx+1;
    int right=2*idx+2;
    //cout<<left<<"                     "<<right<<endl;
    //checking if its not the leaf node
    if(left>=heap.size() && right>=heap.size()){
        return ;
    }
    //calc. index of largest priority
    int parent_idx=idx;
    if(left<heap.size() && heap[left]>heap[parent_idx]){
        parent_idx=left;
    }
    if(right<heap.size() && heap[right]>heap[parent_idx]){
        parent_idx=right;
    }
    if(parent_idx==idx)return;//means its already a max heap
    swap(heap[idx],heap[parent_idx]);
    downheapify(heap,parent_idx);
}

void downheapifyhelper(vector<int > &heap, int idx,int heapsize){
    int left=2*idx+1;
    int right=2*idx+2;
    //checking if its not the leaf node
    if(left>=heapsize && right>=heapsize){
        return ;
    }
    //calc. index of largest priority
    int largest_idx=idx;
    if(left<heapsize && heap[left]>heap[largest_idx]){
        largest_idx=left;
    }
    if(right<heapsize && heap[right]>heap[largest_idx]){
        largest_idx=right;
    }
    if(largest_idx==idx)return;//means its already a max heap
    swap(heap[idx],heap[largest_idx]);
    downheapifyhelper(heap,largest_idx,heapsize);
}

//building optimsed heap in O(N)
void build_heap_optimised(vector< int > &heap){
    for(int i=heap.size()-1;i>=0;i--){
        downheapify(heap,i);
    }
}
//HEAPSORT
void heapsort(vector<int  > &heap){
    int heapsize=heap.size();
    build_heap_optimised(heap);
    for(int i=heap.size()-1;i>=0;i--){ 
        swap(heap[0],heap[i]);
        heapsize-=1;
        downheapifyhelper(heap,0,heapsize);
    }
}

void display(vector<int > &heap ){
    for(auto i: heap){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main() {
    int n,x,idx;
    cin>>n;
    vector<int > heap;
    for(int i=0;i<n;i++){
        cin>>x;
        heap.push_back(x);
    }
    
    heapsort(heap);
    display(heap);
}
