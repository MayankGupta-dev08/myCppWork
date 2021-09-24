// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main(){

// Method 1 to input a string   
    string str1, str2;
    str1 = "Good morning, ";
    cout<<"Enter your name: ";
    cin>>str2;
    // for str2 only first word eneterd will be considered as it is taken using cin
    cout<<str1<<str2<<endl;
    cout<<str1[0]<<endl;

//  Method2: Special case, when you want to string of certain character only with fixed number of repeatitions
    string str3(6, 'o');
    cout<<str3<<endl;

//  Method3: using getline function - consider spaces and more than one word
    string str4;
    cin.ignore();
    // We have used cin.ignore to ignore the last entered character which was an enter from the user at the time of asking str2 using cin.
    getline(cin, str4);
    cout<<str4<<endl;


    string s1 = "abx";
    cout<<s1<<endl;
    s1 = "bfdsjf";  //change original s1, just like for integer
    cout<<s1<<endl;
    return 0;
}