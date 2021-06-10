// To write a program for checking if a number is a pallindrome or not.

#include <iostream>
using namespace std;

int main(){

    int n, reverse_n, lastdigit;
    cout<<"Enter the number for checking if Palindrome or not: ";
    cin>>n;
    reverse_n = 0;
    int original_n = n;
    
    while(n>0){
        lastdigit = n%10;
        reverse_n = reverse_n*10 + lastdigit;
        n=n/10;
    }
    if (original_n==reverse_n){
        cout<<reverse_n<<" is a Pallindrome!"<<endl;
    }
    else{
        cout<<original_n<<" is not a Pallindrome!"<<endl;
    }
    return 0;
}