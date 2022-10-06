# Tree Data Structure

### What is a Tree data structure?

A tree is non-linear and a hierarchical data structure consisting of a collection of nodes such that each node of the tree stores a value and a list of references to other nodes (the “children”).

---

This data structure is a specialized method to organize and store data in the computer to be used more effectively. It consists of a central node, structural nodes, and sub-nodes, which are connected via edges. We can also say that tree data structure has roots, branches, and leaves connected with one another. 

![Tree data structure](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20201129105858/Tree-Basic-Terminology.png)

### Why Tree is considered a non-linear data structure?

The data in a tree are not stored in a sequential manner i.e, they are not stored linearly. Instead, they are arranged on multiple levels or we can say it is a hierarchical structure. For this reason, the tree is considered to be a non-linear data structure.

### Properties of a Tree:
* Number of edges: An edge can be defined as the connection between two nodes. If a tree has N nodes then it will have (N-1) edges. There is only one path from each node to any other node of the tree.
* Depth of a node: The depth of a node is defined as the length of the path from the root to that node. Each edge adds 1 unit of length to the path. So, it can also be defined as the number of edges in the path from the root of the tree to the node.
* Height of a node: The height of a node can be defined as the length of the longest path from the node to a leaf node of the tree.
* Height of the Tree: The height of a tree is the length of the longest path from the root of the tree to a leaf node of the tree.
* Degree of a Node: The total count of subtrees attached to that node is called the degree of the node. The degree of a leaf node must be 0. The degree of a tree is the maximum degree of a node among all the nodes in the tree.

### Some more properties are:

* Traversing in a tree is done by depth first search and breadth first search algorithm.
* It has no loop and no circuit
* It has no self-loop 
* Its hierarchical model.

### Syntax:

```
struct Node
{
   int data;
   struct Node *left_child;
   struct Node *right_child;
};
```