#include<iostream>
using namespace std;

// do while loop executes what inside it once before checking the condition in biginning and from then it checks and proceeds if its true. we use this if we want somthing to run once and from then if condition is true.

int main(){
    // Asking user a number and printing it till it enters a negative integer. 

    int num;

    do{
        cout<<"Enter a number: ";
        cin>>num;
        if (num>=0){
            cout<<"Number is a positive integer: "<<num<<endl;
        }
        else{
            cout<<"Number is a negative integer: "<<num<<endl;
        }
    }while(num>=0);

    return 0;
}