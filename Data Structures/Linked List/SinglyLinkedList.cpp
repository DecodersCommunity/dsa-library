//contributed by : Tanya Rawat , Email : <rawattanya229@gmail.com>
//menu driven program for singly linked list using classes in C++
#include<iostream>
using namespace std;

class Snode{
	public:
		int info;
		Snode *next;
		Snode(){
			info=0;
			next=0;
		}
		Snode(int i, Snode *n=0){
			info=i;
			next=n;
		}
};

class Slist{
	private:
		Snode *head;
		Snode *tail;
	public:
		Slist(){
			head=tail=0;
		}	
		~Slist(){
			Snode *temp;
			while(temp!=0){
				temp=head;
				head=head->next;
				delete temp;
			}
		}	
		void add_to_head(int);
		void add_to_tail(int);
		int delete_from_head();
		int delete_from_tail();
		void delete_node(int);
		bool search(int);
		void concatenate(Slist &s2);
		void display();
		int isEmpty();
		void insert(int,int);
		int remove(int);
};

void Slist::insert(int x,int pos){
	Snode *p=new Snode(x);
	if(pos==1){
		add_to_head(x);
	}
	else{
		int c=1;
		Snode *temp=head;
		while(temp!=0 && c<pos-1){
			c++;
			temp=temp->next;
		}
		if(temp!=0){
			p->next=temp->next;
			temp->next=p;
		}
		else
		{
			cout<<"INVALID POSITION !! ";
		}
	}
}

int Slist::remove(int pos){
	int x=-999;
	if(pos==1){
		x=head->info;
		if(head==tail){
			head=tail=0;
		}
		else{
			Snode *temp=head;
			head=head->next;
			delete(temp);
		}
	}
	else{
		int c=1;
		Snode*temp=head;
		Snode *p=head->next;
		while(p!=0 && c<pos-1){
			c++;
			temp=temp->next;
			p=p->next;
		}
		if(p!=0){
			x=p->info;
			temp->next=p->next;
			delete p;
		}
		else{
			cout<<"INVALID POSITION\n";
		}
	}
	return x;
}
int Slist::isEmpty(){
	if(head==0)
	return 1;
	else
	return 0;
}

void Slist::add_to_head(int i){
	Snode *p=new Snode(i);
	if(isEmpty()){
		head=tail=p;
	}
	else
	{
		p->next=head;
		head=p;
	}
}

void Slist::add_to_tail(int i){
	Snode *p=new Snode(i);
	if(isEmpty())
	head=tail=p;
	else
	{
		tail->next=p;
		tail=p;
	}
}

int Slist::delete_from_head(){
	int x=head->info;
	if(head==tail){
		delete head;
		head=tail=0;
	}
	else
	{
		Snode *temp=head;
		head=head->next;
		delete temp;
	}
	return x;
}

int Slist::delete_from_tail(){
	int x=tail->info;
	if(head==tail){
		delete tail;
		head=tail=0;
	}
	else
	{
		Snode *temp=head;
		Snode *p=head->next;
		while(p->next!=0){
			temp=temp->next;
			p=p->next;}
			tail=temp;
			tail->next=0;
			delete p;}
			return x;		
}	

bool Slist::search(int i){
	Snode *temp=head;
	while(temp!=0 && temp->info!=i)
	temp=temp->next;
	
	if(temp!=0)
	{
	return temp->info;
	}
	else
	return 0;
}

void Slist::concatenate(Slist &s2){
	this->tail->next=s2.head;
	this->tail=s2.tail;
}
void Slist::delete_node(int i){
	if(head==tail && head->info==i){
		delete head;
		head=tail=0;
	}
	else if(head->info==i){
		Snode *temp=head;
		head=head->next;
		delete temp;
	}
	else
	{
		Snode *prev=head;
		Snode *p=head->next;
		while(p!=0 && p->info!=i){
			prev=p;
			p=p->next;
		}
		if(p!=0 && p!=tail){
			prev->next=p->next;
			delete p;
		}
		else if(p==tail && p!=0){
			tail=prev;
			tail->next=0;
			delete p;
		}
		else
		cout<<"Element not found.\n";
	}
}
void Slist::display(){
	Snode *temp=head;
	while(temp!=0){
		cout<<temp->info<<"  ";
		temp=temp->next;
	}
}

int main(){
	char ch;
	int a,option,p;
	Slist l;
	Slist S1; 
	Slist S2;
	cout<<"Enter 0 to stop the program .";
	do{
	cout<<"\n\nSelect the option from below :\n\n";
	cout<<"1. Add to head \n";
	cout<<"2. Add to tail \n";
	cout<<"3. Delete from head \n";
	cout<<"4. Delete from tail \n";
	cout<<"5. Search element\n";
	cout<<"6. Delete Node\n";
	cout<<"7. Concatenate two lists\n";
	cout<<"8. Insert element at specified position\n";
	cout<<"9. Remove from position\n";
	cout<<"\nEnter your option :";
	
	cin>>option;
	switch(option){
		
		case 1:cout<<"Enter element :";
		       cin>>a;
			   l.add_to_head(a);
			   cout<<"The current list is: ";
			   l.display();
			   break;
			   
		case 2:cout<<"Enter element :";
		       cin>>a;
		       l.add_to_tail(a);
		       cout<<"The current list is: ";
			   l.display();
			   break;
			   
		case 3:l.delete_from_head();
			   cout<<"The current list is: ";
			   l.display();
			   break;
			   
		case 4:l.delete_from_tail();
		 	   cout<<"The current list is: ";
			   l.display();
			   break;
		
		case 5:cout<<"Enter element :";
		       cin>>a;
			   if(l.search(a))
			   cout<<"Element is present .";
			   else
			   cout<<"Element is not present .";
			   break;
		
		case 6:cout<<"Enter element to be deleted :";
		       cin>>a;
		       l.delete_node(a);
		       cout<<"The current list is: ";
		       l.display();
		       break;
		       
		case 7:int b,c;
		       cout<<"Enter number of elements for List 1 :";
		       cin>>a;
		       cout<<"Enter elements :";
			   for(int i=0; i<a; i++){
			   	cin>>b;
			   	S1.add_to_tail(b);
			   }
			   cout<<"Enter number of elements for List 2 :";
		       cin>>a;
		       cout<<"Enter elements :";
			   for(int i=0; i<a; i++){
			   	cin>>c;
			   	S2.add_to_tail(c);
			   }
			   S1.concatenate(S2);
			   cout<<"The List after Concatenation is : ";
			   S1.display();
			   break;
		case 8:cout<<"Enter the element :";
		       cin>>a;
		       cout<<"Enter the position :";
		       cin>>p;
		       l.insert(a,p);
		       cout<<"The current list is: ";
		       l.display();
		       break;
		       
		case 9:	cout<<"Enter the position of the element :";
				cin>>p;
				l.remove(p);
				cout<<"The current list is  :";
				l.display();
				break;
				
		default:
			cout<<"\nINVALID OPTION !!";
			break;
	}
}
	while(option!=0);
	return 0;
}