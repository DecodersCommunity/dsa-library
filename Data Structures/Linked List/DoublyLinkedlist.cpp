// Contributed by - Harsh Pratap Singh <hpsingh9536@gmail.com>

       #include <bits/stdc++.h>
       using namespace std;
        
        class node {

                 public:

                    node* prev;
                    int data;
                    node* next;

                    node(int value)  // Constructor for creating node
                    { 
                      prev = NULL; 
                      data = value; 
                      next = NULL; 
                    }

             };



          void insert_at_head(node*& head, int value) // For Inserting from head position
          {

                      node* n = new node(value);
                      n->next = head;

                      if (head != NULL) {
                        head->prev = n;
                      }

                      head = n;
          }


          void insert_at_tail(node*& head, int value)

          {

                      if (head == NULL) {
                        insert_at_head(head, value);
                        return;
                      }

                      node* n = new node(value);
                      node* temp = head;

                      while (temp->next != NULL) {
                        temp = temp->next;
                      }
                      temp->next = n;
                      n->prev = temp;

          }


       void display(node* head)
          {
                    node* temp = head;
                    while (temp != NULL)
                    {
                      cout << temp->data << " --> ";
                      temp = temp->next;
                    }
                    cout << "NULL" << endl;


          }

      void insert_at_position(node*& head , int posn , int d ){
              
            if(posn == 1){
                  insert_at_head(head,d);
                  return ;
              }

              node* temp=head ;
              int cnt =1;

             while(cnt<posn-1)
              {
                  temp=temp->next;
                  cnt++;
              }


              if(temp->next==NULL)
              {
                  insert_at_tail(head,d);
                  return  ;
              }


              node* newnode=new node(d);
              newnode->next=temp->next;
              temp->next->prev=newnode;
              temp->next=newnode;
              newnode->prev=temp;

            
          }

       int main()

            {
                 node* head	= NULL; 

                 //Inserting at tail

                        insert_at_tail(head, 1);
                        insert_at_tail(head, 2);
                        insert_at_tail(head, 3);

                        cout << "After insertion at tail: ";
                        display(head);


                  //Inserting at head

                        insert_at_head(head, 4);
                        insert_at_head(head, 5);
                        insert_at_head(head, 6);

                        cout << "After insertion at head: ";
                        display(head);


                   //Inserting at Index          

                          insert_at_position(head ,4,7);
                          insert_at_position(head ,5,8);
                          insert_at_position(head ,6,9);

                          cout << "After insertion at index: ";
                          display(head);


                    return 0;
          }
