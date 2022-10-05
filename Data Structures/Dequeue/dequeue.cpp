// Contributed by - Nikhil Yadav <devil23042001@gmail.com>

#include<iostream>
using namespace std;
#define SIZE 10
class dequeue {
int a[20], fr ,re;
public:
dequeue();
void insert_starting(int);
void insert_ending(int);
void delete_front();
void ddelete_rear();
void display();
};
dequeue::dequeue() {
fr = -1;
re = -1;
}
void dequeue::insert_ending(int i) {
if ( re>=SIZE-1 ) {
cout << " \n insertion is not possible, overflow!!!! ";
} else {
if ( fr==-1 ) {
fr++;
re++;
} else {
re = re+1;
}
a[re] = i;
cout << " \nInserted item is " << a[re];
}
}
void dequeue::insert_starting(int i) {
if ( fr == -1 ) {
fr = 0;
a[++re] = i;
cout << " \n inserted element is: " << i;
} else if ( fr != 0 ) {
a[--fr] = i;
cout << " \n inserted element is: " << i;
} else {
cout << " \n insertion is not possible, overflow !!! ";
}
}
void dequeue::delete_front() {
if ( fr == -1 ) {
cout << " deletion is not possible :: dequeue is empty ";
return;
}
else {
cout << " the deleted element is: " << a[fr];
if ( fr == re ) {
fr = re = -1;
return;
} else
fr = fr+1;
}
}
void dequeue::ddelete_rear() {
if ( fr == -1 ) {
cout << " deletion is not possible::dequeue is empty ";
return;
}
else {
cout << " the deleted element is: " << a[re];
if ( fr == re ) {
fr = re = -1;
} else
re = re-1;
}
}
void dequeue::display() {
if ( fr == -1 ) {
cout << " Dequeue is empty ";
} else {
for ( int i = fr; i <= re; i++ ) {
cout << a[i]<< " ";
}
}
}
int main () {
int c,i;
dequeue d;
do{
cout << " \n 1.insert element at the beginning ";
cout << " \n 2.insert element at the end ";
cout << " \n 3.displaying the elements ";
cout << " \n 4.deletion of elements from front ";
cout << " \n 5.deletion of elements from rear ";
cout << " \n 6.exiting the queue ";
cout << " \n Please enter your choice: ";
cin>>c;
switch(c) {
case 1:
cout << " Please enter the element to be inserted ";
cin>>i;
d.insert_starting(i);
break;
case 2:
cout << " Please enter the element to be inserted ";
cin >> i;
d.insert_ending(i);
break;
case 3:
d.display();
break;
case 4:
d.delete_front();
break;
case 5:
d.ddelete_rear();
break;
case 6:
exit(1);
break;
default:
cout << " invalid choice, Please enter valid choice ";
break;
}
} while (c!=7);
}
