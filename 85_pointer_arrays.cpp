// To write a program ..
// Array is an indexing pointer which uses the index to change its location, where as pointer on an increment moves to next memory location on based of data type
// When we write *arr for arr[10], then it will print the first element (index 0)

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int arr[] = {10,20,30,40,50};
    cout<<*arr<<endl;        //value of element of index 0
    cout<<*(arr+1)<<endl;    //value of element of index 1
    cout<<*(arr+3)<<endl;    //value of element of index 1
    cout<<arr[0]<<endl;      //value of element of index 0
    cout<<arr<<endl;         //address of index 0 element

// Normally printing the elements of array
    for (int i = 0; i < 5; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;

// using array as pointer
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++){
        cout<<*(arr+i)<<" ";
        //(arr+i) will point to ith element and *(arr+i) will give its value.
        
        // arr++; //It is illegal in case of arays as arr will only store the address of index0 element and we can play with it to get others just by adding some int value so that it gives the element of that int value index but we can't change the address value of arr pointer as it always points to index0, otherwise it won't be pointing to array if we try to change it so its not legal.
    }
    cout<<endl;

// Doing same thing using pointers
    int *ptr = arr;
    for (int i = 0; i < 5; i++){
        cout<<*ptr<<" ";
        ptr++;
    }
    cout<<endl;
    return 0;
}