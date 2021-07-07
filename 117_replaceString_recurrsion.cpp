// To write a program ..to give the required output for the given input using recurrsion

    // input    - pippppiiiipi
    // output   - 3.14ppp3.14iii3.14

    // input    - pippxxppiixipi
    // output   - 3.14ppxxp3.14ixi3.14


//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void replacePi(string s){
    if(s.length()==0)       //base case
        return;

    if(s[0]=='p' && s[1]=='i'){
        cout<<3.14;
        replacePi(s.substr(2));      
        // creating a substring biginning from index2 of s and sending it in replace function so reducing it everytime if pi is found at 0
    }
    else{
        cout<<s[0];
        replacePi(s.substr(1));
    }
}

int main(){

    string s = "pippxxppiixipi";        
    replacePi(s);
    cout<<endl;
    return 0;
}