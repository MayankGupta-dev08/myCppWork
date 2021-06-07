#include<iostream>
using namespace std;

// While loop checks the condition in biginning before entering the loop and we use this instead of for loop when we don't know how many times the loop is going to run, rather we know condition only.

int main(){
    // Asking user a number and printing it till it enters a negative integer. 

    int num;
    cout<<"Enter a number: ";
    cin>>num;
    while(num>=0){
        cout<<"Number is a positive integer: "<<num<<endl;
        cout<<"Enter again: ";
        cin>>num;
    }
    cout<<"Number is a negative integer: "<<num<<endl;

    return 0;
}