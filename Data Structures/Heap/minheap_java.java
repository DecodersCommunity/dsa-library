// Name:Siddharth chandrakar  email:siddharthchandrakar@gmail.com
// Custom min heap implementation in java

import java.util.*;
class minheap_java{
    static class CustomHeap<T extends Comparable<T>>{
        ArrayList<T>al;
        CustomHeap(){
            al=new ArrayList<>();
        }
        public void insert(T data){
            al.add(data);
            upHeapify(al.size()-1);
        }
        

        public T remove(){    //O(logn  )
            if(al.size()==0){
                return null;
            }
            if(al.size()==1){
                return al.remove(0);
            }
            T ans=al.get(0);
            al.set(0,al.get(al.size()-1));
            al.remove(al.size()-1);
            downHeapify(0);
            return ans;
        }
        public void upHeapify(int id){   //logn
            if(id==0){
                return;
            }
            int parent=myParent(id);
            if(al.get(parent).compareTo(al.get(id))>0){
                T temp=al.get(id);
                al.set(id,al.get(parent));
                al.set(parent,temp);
            }
            upHeapify(parent);
        } 
        public void downHeapify(int id){  //logn
            int min=id; 
            int lc=leftChild(id);
            int rc=rightChiled(id);
            if(lc<al.size()&&al.get(lc).compareTo(al.get(min))<0){
                min=lc;
            }
            if(rc<al.size()&&al.get(rc).compareTo(al.get(min))<0){
                min=rc;
            }
            if(min!=id){
                T temp=al.get(id);
                al.set(id,al.get(min));
                al.set(min,temp);
                downHeapify(min);
            }
        }
        public int myParent(int id){
            return (id-1)/2;
        }
        public int leftChild(int id){
            return 2*id+1;
        }
        public int rightChiled(int id){
            return 2*id+1;
        }
        public String toString(){
            return al.toString();
        }
    } 
    public static void main(String args[]){
     int arr[]={10,3,5,11,6,12,2,15,8};
     CustomHeap<Integer>cs1=new CustomHeap<>();
     for(int ele:arr){
        cs1.insert(ele);
     }
    System.out.println(cs1);
     System.out.println(cs1.remove());
     System.out.println(cs1);
    }
}

            //           2 
            //         /   \
            //        /     \
            //       6        3
            //      / \       / \
            //     8   10    12  5
            //    /      \
            //   15       11