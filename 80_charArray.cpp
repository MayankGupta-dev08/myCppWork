// To write a program ..
// we we want to have a char array of n elemets than we have to make of size n+1 to mention the escape character or null character'\0' as the end char of that array.

//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

int main(){

    char a[100] = "An apple a day keeps a doctor away";
    for(int i=0; a[i]!='\0'; i++){
        cout<<a[i];
    }
    cout<<endl;
    for(int i=0; a[i]!='\0'; i++){
        cout<<a[i]<<endl;
    }
    
    // We can also directly take input if there are no spaces between the characters in the word
    char b[100];
    cout<<"enter a single word without spaces: ";
    cin>>b;
    cout<<b<<endl;
    cout<<b[1]<<endl;

    return 0;
}