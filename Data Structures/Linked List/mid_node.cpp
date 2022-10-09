//Contributed By- Shashank Rai(shashank.rai00331@gmail.com)

// Given a linkedlist we have to find the mid of the linkedlist 

// For this we have to basically find the len and divide it by 2 
//  case1 --> len is even =  (len-1)/2
//  case2 --> len is add =  (len-1)/2

// ---------------------------------------------------------

// Can we do this without finding th len of our linkedlist

// two pointers 
// 1 - slow = we placed it at head  (jump 1 node at one time)
// 2 - fast = we placed it at the next of head ( jump 2 nodes )

// 

class Solution {
public:
    Node* middleNode(Node* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next; 
        }
        
        return slow;
    }
};