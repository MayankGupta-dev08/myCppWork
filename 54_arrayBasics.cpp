// To write a program ..

#include <iostream>
using namespace std;

int main(){

    int array1[5] = {10,20,30,40,50};
    char array2[5] = {'1','2','3','4','5'};
    string array3[5] = {"ten", "twenty", "thirty", "forty", "fifty"};
    // We can't print the whole array just by using it's name as we can do with list in python, also here array can only have elements of one type in an array at a time.

    for(int i=0; i<5; i++){
        cout<<array2[i]<<" : "<<array1[i]<<" : "<<array3[i]<<endl;    
    }
    cout<<endl;

    int n;
    cout<<"Enter the size of array1: ";
    cin>>n;
    int a[n];
    
    for(int i=0; i<n; i++){
        cin>>a[i];    
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";    
    }
    
    cout<<endl;
    return 0;
}