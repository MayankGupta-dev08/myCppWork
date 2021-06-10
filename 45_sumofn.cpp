// Sum of first n natural numbers...

// To write n program ..

#include <iostream>
using namespace std;

int main(){

    int n, sum = 0;;
    // cout<<"Enter the number: ";
    cin>>n;
    
    // for(int i=1; i<=n; i++){
    // sum +=i;
    // }

    sum = (n*(n+1))/2;
    cout<<"Sum of first 'n' natural numbers: "<<sum<<endl;
    return 0;
}