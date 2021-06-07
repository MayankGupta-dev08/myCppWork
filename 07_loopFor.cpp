#include<iostream>
using namespace std;

// We know condition, how many time its going to run and incremental value.
int main(){

    int num, sum, i;
    cout<<"Enter a number: ";
    cin>>num;
    sum=0;
    for (i=1; i<=num; i++){
        sum = sum + i;
    }
    cout<<"Sum of all natural numbers till "<<num<<" is: "<<sum<<endl;

    return 0;
}