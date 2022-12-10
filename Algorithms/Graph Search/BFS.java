//  Contributed by - Ohene Neil <neilohene@gmail.com>

import java.io.*;
import java.util.*;


/* GENERAL IMPLEMENTATION PROCESS
 * Take input for the adjacency list for the graph.
 * Initialize a queue.
 * Enqueue the root node
 * Remove first element of the queue, then enqueue all of its neighboring nodes, by traversal (starting from left to right).
 * If a node has no neighboring nodes which need to be explored, simply dequeue the head and continue the process.
 * Repeat process until queue is empty 
*/

public class Graph {
        private int N;                                                  //number of nodes in the graph
	    private LinkedList<Integer> adj[];                              //adjacency list
    	private Queue<Integer> queue;                                   //maintaining a queue
 
 	    Graph(int v) {
            	N = v;
        	    adj = new LinkedList[v];
        	
		        for (int i = 0; i < v; i++) {
            	        adj[i] = new LinkedList<>();
        	    }
        
		        queue = new LinkedList<Integer>();
    	}

 
	    void addEdge(int v,int w) {
		        adj[v].add(w);                          
    	}
 
 	    void BFS(int n) {
                boolean nodes[] = new boolean[N];                       //initialize boolean array for holding the data
                int a = 0;
                
                nodes[n]=true;                  
                queue.add(n);                                           

                while (queue.size() != 0) {
                        n = queue.poll();                               //remove the top element of the queue
                        System.out.print(n + " ");                      //print the top element of the queue
        
                        for (int i = 0; i < adj[n].size(); i++) {       //iterate through the linked list and push all neighbors into queue
                                a = adj[n].get(i);
                                if (!nodes[a]) {	                    // insert nodes into queue only if they have not been explored
                                        nodes[a] = true;
                                        queue.add(a);
                                    }
                        }  
                }
        }
}