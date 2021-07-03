// To write a program ..to move all x to end of the string

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string moveToEnd_x(string s){
    if (s.length()==0)
        return "";
    
    char ch = s[0];
    string restStr = moveToEnd_x(s.substr(1));      
    //here we are saying that bythe help of recurrsion this would be corrected till the time we will add this s[0] to rest.
    
    if (ch=='x')
        return (restStr+ch);
    else
        return (ch+restStr);

}



int main(){
    
    cout<<moveToEnd_x("axxbdxcefxhix")<<endl;
    // abdcefhixxxxx
    return 0;
}