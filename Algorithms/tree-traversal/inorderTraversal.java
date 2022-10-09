
// Siddharth chandrakar  siddharthchandrakar007@gmail.com



// package Algorithms.tree-traversal;
import java.util.*;
public class inorderTraversal {

    class Node{
        int value;
        Node left;
        Node right;
        Node(int value){
            this.value=value;
            this.left=null;
            this.right=null;
        }

    }
    private Node root;
    public  void insert(int data,String dir){
        root=insert(data, dir,root,0);
    }
    private  Node insert (int data,String dir,Node myNode,int idx){
        if(myNode==null){
            myNode=new Node(data);
            return myNode;
        }
        if(dir.length()==idx){
            myNode.value=data;
            return myNode;
        }
        if(dir.charAt(idx)=='L'){
            myNode.left=insert(data, dir, myNode.left, idx+1);
        }else{
            myNode.right=insert(data, dir, myNode.right, idx+1);
        }
        return myNode;
    }

    public void display(){
        display(root);
    }
    public void display(Node myNode){
        if(myNode==null){
            return;
        }
        if(myNode.left!=null){
                       System.out.print(myNode.left.value+"->");
                   }else {
                       System.out.print(" ->");
                   }
                   System.out.print(myNode.value);
                   if(myNode.right!=null){
                       System.out.print("<-"+myNode.right.value);
                   }else {
                       System.out.print(" <-");
                   }
                   System.out.println();
                   display(myNode.left);
                   display(myNode.right);
    }


    public ArrayList<Integer> inOrder(){
        ArrayList<Integer>al=new ArrayList();
        return inOrder(root,al);
    }
    public ArrayList<Integer> inOrder(Node myNode,ArrayList<Integer>al){
        
        if(myNode==null){
            return al;
        }
        
        
        inOrder(myNode.left,al);
        al.add(myNode.value);
        inOrder(myNode.right,al);
        
        return al;
    }
    public static void main(String args[]){
    
        inorderTraversal ob=new inorderTraversal();
        ob.insert(1,"");
        ob.insert(0,"L");
        ob.insert(2,"R");
        ob.insert(3,"RL");
        ob.display();
        System.out.println("IN-ORDER "+ob.inOrder());
    }
    
}

