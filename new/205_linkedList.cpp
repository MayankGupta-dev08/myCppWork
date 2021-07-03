/*LINKED LIST
1.  it is a linear data structure
2.  it is a collection of data elements which are stored in non-consecutive locations
3.  Some extra sapce is required to store the pointers
4.  Random access is not possible, u have to traverse whole
5.  Insertion and deletion is easy
6.  as the name suggest it is a list which is made up of links
7. it is of dynamic size
8. it is user defined data type
9. acessing any element is order of n, where as in array it is order of 1
10. binary search is not possible
11. starting element is head and each element's pointer stores the address of next element, where as last element has null pointer
12. collection of data and link is called a node
*/

#include <iostream>
using namespace std;

//Creating Node Structure
// self referencing structure
struct Node{
 int data;
 Node *link;    //since we want to point variable of type node
};

//creating head pointer and equating to NULL
Node *head=NULL;

//Main Method
int main(){

    //Creating a new Node
    // this will be our first node
    Node *ptr=new Node();
    //Adding data and setting link to NULL
    ptr->data=2;
    ptr->link=NULL;
    
    //Pointing head to created Node
    // copy all things of ptr to head
    head=ptr;   //so that we can know this ptr is starting node
    cout<<"head data is "<<head->data<<endl;
    cout<<"head link is "<<head->link<<endl;
    cout<<"ptr data is "<<ptr->data<<endl;
    cout<<"ptr link is "<<ptr->link<<endl;
    return 0;
}