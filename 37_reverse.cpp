// To write a program for printing reverse of a number.

#include <iostream>
using namespace std;

int main(){

    int n, reverse_n, lastdigit;
    cout<<"Enter the number for which you want reverse: ";
    cin>>n;
    reverse_n = 0;

    while(n>0){
        lastdigit = n%10;
        reverse_n = reverse_n*10 + lastdigit;
        n=n/10;
    }
    cout<<reverse_n<<endl;
    return 0;
}