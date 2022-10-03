
/*
Contributed by Harsh Pratap Singh <hpsingh9536@gmail.com>

*There is Doubly - linked list head and we want to delete a node node in it using C.

*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};
int getLength(struct Node* node);

void insert(struct Node** head, int data){

    struct Node* freshNode = (struct Node*) malloc(sizeof(struct Node));

    freshNode->data = data;
    freshNode->next = *head;
    freshNode->prev = NULL;

    // If the linked list already had atleast 1 node
    if(*head !=NULL)
        (*head)->prev = freshNode;

    // freshNode will become head
    *head = freshNode;
}

void deleteFront(struct Node** head)
{
    struct Node* tempNode = *head;
  
    // if DLL is empty
    if(*head == NULL){
        printf("Linked List Empty, nothing to delete\n");
        return;
    }
    
    // if Linked List has only 1 node
    if(tempNode->next == NULL){
        printf("%d deleted\n", tempNode->data);
        *head = NULL;
        return;
    }
    
    // move head to next node
    *head = (*head)->next;
    // assign head node's previous to NULL
    (*head)->prev = NULL;
    
    printf("%d deleted\n", tempNode->data);
    free(tempNode);
}

void deleteEnd(struct Node** head){
    struct Node* tempNode = *head;

    // if DLL is empty
    if(*head == NULL){
        printf("Linked List Empty, nothing to delete\n");
        return;
    }
    
    // if Linked List has only 1 node
    if(tempNode->next == NULL){
        printf("%d deleted\n", tempNode->data);
        *head = NULL;
        return;
    }
    
    // else traverse to the last node
    while (tempNode->next != NULL) 
        tempNode = tempNode->next; 
    
    struct Node* secondLast = tempNode->prev;
    
    // Curr assign 2nd last node's next to Null
    secondLast->next = NULL;
    
    printf("%d deleted\n", tempNode->data);
    free(tempNode);
}

void deleteNthNode(struct Node** head, int n){
    //if the head node itself needs to be deleted
    int len = getLength(*head);
    
    // not valid
    if(n < 1 || n > len){
        printf("Enter valid position\n");
        return;
    }
    
    // delete the first node
    if(n == 1){
        deleteFront(head);
        return;
    }
    
    if(n == len){
        deleteEnd(head);
        return;
    }
    
    struct Node* tempNode = *head;
    
    // traverse to the nth node
    while (--n){
        tempNode = tempNode->next; 
    }
    
    struct Node* previousNode = tempNode->prev; // (n-1)th node
    struct Node* nextNode = tempNode->next; // (n+1)th node
    
    // assigning (n-1)th node's next pointer to (n+1)th node
    previousNode->next = tempNode->next;

    // assigning (n+1)th node's previous pointer to (n-1)th node
    nextNode->prev = tempNode->prev;
    
    // deleting nth node
    printf("%d deleted \n", tempNode->data);
    free(tempNode);
}
// required for deleteNthNode
int getLength(struct Node* node){
    int len = 0;
    

    while(node!=NULL){
        node = node->next;
        len++;
    }
    
    return len;
}

//function to print the doubly linked list
void display(struct Node* node) 
{ 
    struct Node *end = NULL;
    
    printf("List in Forward direction: ");
    while (node != NULL) { 
        printf(" %d ", node->data); 
        end = node;
        node = node->next; 
    }
    
    printf("\nList in backward direction:");

    while (end != NULL) { 
        printf(" %d ", end->data); 
        end = end->prev; 
    }
    printf("\n\n");
}

int main()
{
    struct Node* head = NULL;

    insert(&head,7);
    insert(&head,8);
    insert(&head,9);
    insert(&head,10);
    insert(&head,11);
    insert(&head,12);
  
    display(head);
    
    deleteFront(&head);
    display(head);
        
    deleteEnd(&head);
    display(head);

    // delete 3rd node
    deleteNthNode(&head, 3);
    display(head);    
    
    // delete 1st node
    deleteNthNode(&head, 1);
    display(head);
    
    // delete 1st node
    deleteEnd(&head);
    display(head);
    
    
    return 0;
}
