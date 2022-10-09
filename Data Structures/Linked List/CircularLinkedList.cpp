//contributed by : Tanya Rawat , Email : <rawattanya229@gmail.com>
//menu driven program for Circular linked list using classes in C++
#include<iostream>
using namespace std;

template<class T>
class Cnode{
	public:
		T info;
		Cnode<T> *next;
		Cnode(){
			info=0;
			next=0;
		}
		Cnode(T i, Cnode *n=0){
			info=i;
			next=n;
		}
};
template<class T>
class Clist{
	private:
		Cnode<T> *tail;
	public:
		Clist(){
			tail=0;
		}	
		void add_to_head(T);
		void add_to_tail(T);
		T delete_from_head();
		T delete_from_tail();
		void delete_node(T);
		void search(T);
		void display();
		T isEmpty();
		void insert(T,int);
		void concatenate(Clist &C2);
};
template<class T>
void Clist<T>::delete_node(T x){
	if(isEmpty())
      return ;
   else
   {
      Cnode<T> *temp1 =tail->next, *temp2;
      while(temp1 ->info!=x)
      {
         if(temp1->next==tail->next)
         {
           cout<<"Element not Found.\n";
           return ;
         }
         else
         {
            temp2 = temp1;
            temp1 = temp1 -> next;
         }
      }
      if(temp1 -> next == tail->next){
         tail->next= NULL;
         delete temp1;
      }
      else{
         if(temp1 == tail->next)
         {
            temp2 =tail->next;
            while(temp2 -> next !=tail->next)
               temp2 = temp2 -> next;
            tail->next=tail->next->next;
            temp2 -> next =tail->next;
            delete temp1;
         }
         else
         {
            if(temp1 -> next == tail->next)
            {
               temp2 -> next =tail->next;
            }
            else
            {
               temp2 -> next = temp1 -> next;
            }   
            delete temp1;
         }
      }
      cout<<"Element Deleted. \n";
   }
}
template<class T>
void Clist<T>::insert(T x,int pos){
	Cnode<T> *p=new Cnode<T>(x);
	if(pos==1){
		add_to_head(x);
	}
	else{
		int c=1;
		Cnode<T> *temp=tail->next;
		do{
			c++;
			temp=temp->next;
		}
		while(temp!=tail->next && c<pos-1);
		if(temp==tail){
			add_to_tail(x);
		}
	    else if(temp!=tail->next){
			p->next=temp->next;
			temp->next=p;
	}
		else
		{
			cout<<"INVALID POSITION !! \n\n";
		}
	}
}
template<class T>
void Clist<T>::concatenate(Clist &C2){
	Cnode<T> *tp=tail->next;
	this->tail->next=C2.tail->next;
	this->tail->next=C2.tail->next;
	C2.tail->next=tp;
}
template<class T>
T Clist<T>::isEmpty(){
	if(tail==0)
	return 1;
	else
	return 0;
}
template<class T>
void Clist<T>::add_to_head(T i){
	Cnode<T> *p=new Cnode<T>(i);
	if(isEmpty()){
		tail=p;
		tail->next=tail;
	}
	else
	{
		p->next=tail->next;
		tail->next=p;
	}
}
template<class T>
void Clist<T>::add_to_tail(T i){
	Cnode<T> *p=new Cnode<T>(i);
	if(isEmpty()){
		tail=p;
		tail->next=tail;
	}
	else
	{
		p->next=tail->next;
		tail->next=p;
		tail=p;
	}
}
template<class T>
T Clist<T>::delete_from_head(){
	if(isEmpty()){
		return 0;
	}
	else{
	int x=tail->next->info;
	if(tail==tail->next){
		delete tail;
		tail=0;
	}
	else
	{
		Cnode<T> *temp=tail->next;
		tail->next=temp->next;
		delete temp;
	}
	return x;
	}
}
template<class T>
T Clist<T>::delete_from_tail(){
	if(isEmpty()) return 0;
	else{
	int x=tail->info;
	if(tail==tail->next){
		delete tail;
		tail=0;
	}
	else
	{
		Cnode<T> *p=tail->next;
		while(p->next!=tail){
			p=p->next;}
			p->next=tail->next;
			delete tail;
			tail=p;
	}
	return x;
	}
}
template<class T>
void Clist<T>::search(T i){
	Cnode<T> *temp=tail->next;
	int found=0;{
		while(true){
			if(temp->info==i){
				found++; break;
			}
			temp=temp->next;
			if(temp==tail->next) break;
		}
		if(found==1) cout<<i<<" is present in the list .\n";
		else cout<<i<<" is not present in the list .\n";
	}
}
template<class T>
void Clist<T>::display(){
	if(isEmpty()){
		cout<<"The list is Empty .\n";
	}
	else{
		Cnode<T> *temp=tail->next;
	cout<<"The current List is : ";
	while(temp!=tail){
		cout<<temp->info<<"  ";
		temp=temp->next;
	}
	cout<<temp->info<<"  ";}
}

int main(){
	char ch;
	int option,p;
	Clist<int> l;
	Clist<int> C1,C2;
	int a;
	cout<<"To close the program press 0. ";
	do{
	cout<<"\nSelect the option from below :\n\n";
	cout<<"1. Add to head \n";
	cout<<"2. Add to tail \n";
	cout<<"3. Delete from head \n";
	cout<<"4. Delete from tail \n";
	cout<<"5. Search element\n";
	cout<<"6. Delete Node\n";
	cout<<"7. Insert \n";
	cout<<"8. Concatenate two List\n";
	cout<<"9. Display List \n";
	cout<<"\nEnter your option :";
	cin>>option;
	switch(option){
		
		case 1:cout<<"Enter element :";
		       cin>>a;
			   l.add_to_head(a);
			   l.display();
			   break;
			   
		case 2:cout<<"Enter element :";
		       cin>>a;
		       l.add_to_tail(a);
			   l.display();
			   break;
			   
		case 3:l.delete_from_head();
		l.display();
			   break;
			   
		case 4:l.delete_from_tail();
		l.display();
			   break;
		case 5:if(l.isEmpty()) cout<<"The list is Empty .\n";
				else{
			   cout<<"Enter element :";
		       cin>>a;
		       l.search(a);}
		       break;
		case 6:if(l.isEmpty())
				cout<<"The list is Empty.\n";
				else{
			   cout<<"Enter element to be deleted :";
		       cin>>a;
		       l.delete_node(a);
		       l.display();}
		       break;
		case 7: if(l.isEmpty())
				cout<<"The list is Empty.\n";
				else{
				cout<<"Enter element :";
				cin>>a;
				cout<<"Enter Position : ";
				cin>>p;
				l.insert(a,p);
				l.display();}
				break;
		case 8:
			   int b,c;
		       cout<<"Enter number of elements for List 1 :";
		       cin>>a;
		       cout<<"Enter elements :";
			   for(int i=0; i<a; i++){
			   	cin>>b;
			   	C1.add_to_tail(b);
			   }
			   cout<<"Enter number of elements for List 2 :";
		       cin>>a;
		       cout<<"Enter elements :";
			   for(int i=0; i<a; i++){
			   	cin>>c;
			   	C2.add_to_tail(c);
			   }
			   C1.concatenate(C2);
			   cout<<"The List after Concatenation is : \n";
			   C1.display();
			   break;
		case 9:
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
