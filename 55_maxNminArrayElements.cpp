// To write a program ..

#include <iostream>
#include <climits> //for INT_MIN and INT_MAX
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array1: ";
    cout<<"Enter the elements: ";
    cin>>n;
    int a[n], mx,mn;
    
    for(int i=0; i<n; i++){
        cin>>a[i];   
    }
    mx = INT_MIN; //Gives the min possible int b=value in c++.
    mn = INT_MAX; //Gives the max possible int b=value in c++.
    // mx = a[0];
    // mn = a[0];
    cout<<"Your Entered elements are:\n{ ";
    for(int i=0; i<n; i++){
        if (mx<a[i]){
            mx=a[i];
        }
        if (mn>a[i]){
            mn=a[i];
        }
        cout<<a[i]<<" ";    
    }
    cout<<"}"<<endl;
    cout<<"Max from array: "<<mx<<endl;
    cout<<"Min from array: "<<mn<<endl;
    return 0;
}