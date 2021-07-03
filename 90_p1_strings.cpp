// To write a program ..to capitalize the lowercase character and vice versa for a string.

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main(){

    // ASCI values of A is 65 and a is 97, so difference is 32.

    string str = "ANDAScnbvzcurKJDA";
    cout<<str<<endl;
    for (int i = 0; i < str.size(); i++){
        if (str[i]>= 'a' && str[i]<='z'){
            str[i] -= 32;
        }
        else if(str[i]>= 'A' && str[i]<='Z'){
            str[i] += 32;
        }
    }
    cout<<str<<endl;

    // using transform() to do the thing
    string s1 = "bsdjkhaskjdhs";  
    string s2 = "ASEPEIFDGVCIE";  
    
    cout<<s1<<endl;
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    cout<<s1<<endl;

    cout<<s2<<endl;
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout<<s2<<endl;

    return 0;
}