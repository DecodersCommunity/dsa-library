
// Siddharth chandrakar  siddharthchandrakar007@gmail.com



// package Algorithms.tree-traversal;
import java.util.*;
public class postorderTraversal {

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
    public ArrayList<Integer> postOrder(){
        ArrayList<Integer>al=new ArrayList();
        return postOrder(root,al);
    }
    public ArrayList<Integer> postOrder(Node myNode,ArrayList<Integer>al){
        
        if(myNode==null){
            return al;
        }
        
        
        postOrder(myNode.left,al);
        postOrder(myNode.right,al);
        al.add(myNode.value);
        return al;
    }
    public static void main(String args[]){
    
        postorderTraversal ob=new postorderTraversal();
        ob.insert(1,"");
        ob.insert(0,"L");
        ob.insert(2,"R");
        ob.insert(3,"RL");
        ob.display();
        System.out.println("POST-ORDER "+ob.postOrder());
    }
    
}

