
/*
Contributed by Harsh Pratap Singh <hpsingh9536@gmail.com>

*There is Doubly - linked list head and we want to delete a node node in it.

*/


    #include <iostream>
    #include <stdlib.h>
    using namespace std;

    struct node {
        int num;
        struct node * preptr;
        struct node * nextptr;
    }*start_node, *end_node;


    void Listcreation(int n);
    void DeleteFirstnode();
    void DeleteLastnode();
    void DeleteAnyNode(int pos);
    void display(int a);

    int main()
    {
        int n,num1,a,insPlc;
        start_node = NULL;
       end_node= NULL;

        cout<<" Enter the number of nodes : ";
        cin>>n;
        Listcreation(n); 
        a=1;
        display(a);
        cout<<" Enter the position  to delete a node : ";
        cin>>insPlc;


    if(insPlc<1 || insPlc>n)
        {
         cout<<"\n Invalid position. Try again.\n ";
        }
              if(insPlc>=1 && insPlc<=n)
          {

        DeleteAnyNode(insPlc);  
            a=2;
        display(a);
          }    
        return 0;
    }

    void Listcreation(int n)
    {
        int i, num;
        struct node *fnNode;

        if(n >= 1)
        {
            start_node = (struct node *)malloc(sizeof(struct node));

            if(start_node != NULL)
            {
                cout<<" Enter data for node 1: "; // storing data in the first node
                cin>>num;

                start_node->num = num;
                start_node->preptr = NULL;
                start_node->nextptr = NULL;
                end_node= start_node;
                for(i=2; i<=n; i++)
                {
                    fnNode = (struct node *)malloc(sizeof(struct node));
                    if(fnNode != NULL)
                    {
                        cout<<" Enter data for node "<<i<<": ";
                        cin>>num;
                        fnNode->num = num;
                        fnNode->preptr = end_node;      // linking new nodes
                        fnNode->nextptr = NULL;        // setting the address of last node to NULL
                        end_node->nextptr = fnNode;   // previous node is linking with the new node
                        end_node= fnNode;            // assign new node as last node
                    }
                    else
                    {
                        cout<<" Memory can not be allocated.";
                        break;
                    }
                }
            }
            else
            {
                cout<<" Memory can not be allocated.";
            }
        }
    }

    void DeleteAnyNode(int pos)
    {
        struct node *curNode;
        int i;

        curNode = start_node;
        for(i=1; i<pos && curNode!=NULL; i++)
        {
            curNode = curNode->nextptr;
        }

        if(pos == 1)
        {
           DeleteFirstnode();
        }
        else if(curNode == end_node)
        {
            DeleteLastnode();
        }
        else if(curNode != NULL)
        {
            curNode->preptr->nextptr = curNode->nextptr;
            curNode->nextptr->preptr = curNode->preptr;

            free(curNode); //Deleting nth the node
        }
        else
        {
            cout<<" The given position is invalid!\n";
        }
    } 

    void DeleteFirstnode()//deleting the first node
    {
        struct node * NodeToDel;
        if(start_node == NULL)//checking if the first node is the last node or not
        {
            cout<<" Delete is not possible. No data in the list.\n";
        }
        else   
        {
            NodeToDel = start_node;
            start_node = start_node->nextptr;   
            start_node->preptr = NULL;     
            free(NodeToDel);           
        }
    }

    void DeleteLastnode()//deleting the last node
    {
        struct node * NodeToDel;

        if(end_node== NULL)//checking whether the list has any nodes or not
        {
            cout<<" Delete is not possible. No data in the list.\n";
        }
        else
        {
            NodeToDel = end_node;
            end_node= end_node->preptr;    
            end_node->nextptr = NULL;   
            free(NodeToDel);        
        }
    }
    void display(int m)
    {
        struct node * tmp;
        int n = 1;
        if(start_node == NULL)
        {
            cout<<" No data found in the List yet.";
        }
        else
        {
            tmp = start_node;
            if (m==1)
            {
            cout<<"\n Data entered in the list are :\n";
            }
            else
            {
             cout<<"\n After deletion the new list are :\n";   
            }
            while(tmp != NULL)
            {
                cout<<" node "<< n<<": "<< tmp->num<<endl;
                n++;
                tmp = tmp->nextptr; // current pointer moves to the next node
            }
        }
    }
