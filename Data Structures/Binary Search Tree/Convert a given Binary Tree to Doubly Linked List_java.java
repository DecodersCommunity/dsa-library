Name: Sudip Parajuli
email: parajulisudip123@outlook.com
class Node
{
    int data;
    Node left, right;
  
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
  
class BinaryTree
{
    Node root;
    /* This is the core function to convert Tree to list. This function
       follows steps 1 and 2 of the above algorithm */
  
    Node bintree2listUtil(Node node)
    {
        // Base case
        if (node == null)
            return node;
        if (node.left != null)
        {
            Node left = bintree2listUtil(node.left);
 
            for (; left.right != null; left = left.right);
  
            left.right = node;
  
            node.left = left;
        }
  
        if (node.right != null)
        {
            // Convert the right subtree
            Node right = bintree2listUtil(node.right);
  
            // Find inorder successor. After this loop, right
            // will point to the inorder successor
            for (; right.left != null; right = right.left);
  
            // Make root as previous of successor
            right.left = node;
  
            // Make successor as next of root
            node.right = right;
        }
  
        return node;
    }
  
    // The main function that first calls bintree2listUtil(), then follows
    // step 3 of the above algorithm
      
    Node bintree2list(Node node)
    {
        // Base case
        if (node == null)
            return node;
  
        // Convert to DLL using bintree2listUtil()
        node = bintree2listUtil(node);
  
        // bintree2listUtil() returns root node of the converted
        // DLL.  We need pointer to the leftmost node which is
        // head of the constructed DLL, so move to the leftmost node
        while (node.left != null)
            node = node.left;
  
        return node;
    }
  
   
    void printList(Node node)
    {
        while (node != null)
        {
            System.out.print(node.data + " ");
            node = node.right;
        }
    }

    public static void main(String[] args)
    {
        BinaryTree tree = new BinaryTree();
  
        // Let us create the tree shown in above diagram
        tree.root = new Node(10);
        tree.root.left = new Node(12);
        tree.root.right = new Node(15);
        tree.root.left.left = new Node(25);
        tree.root.left.right = new Node(30);
        tree.root.right.left = new Node(36);
  
        // Convert to DLL
        Node head = tree.bintree2list(tree.root);
  
        // Print the converted list
        tree.printList(head);
    }
}
