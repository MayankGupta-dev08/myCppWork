// To write a program ..to print All possible Words From given digits of a Phone Keypad using recurrsion

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string keyPad[] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void allWords_phnDigit(string inp_s, string op_s){
    if(inp_s.length()==0){
        cout<<op_s<<endl;
        return;
    }
    
    char ch = inp_s[0];                               //2 
    // from this we will tell which string to choose
    string alpha = keyPad[ch - '0'];                //alpha = "abc"

    for (int i = 0; i < alpha.length(); i++){
        allWords_phnDigit( inp_s.substr(1), (op_s + alpha[i]) );    
        //("3",  ""+'a') 
        //("",  ""+'ad')    ("",  ""+'ae')  ("",  ""+'af')
        //("3",  ""+'b')
        //("",  ""+'bd')    ("",  ""+'be')  ("",  ""+'bf')
        //("3",  ""+'c')
        //("",  ""+'cd')    ("",  ""+'ce')  ("",  ""+'cf')
    }
}



int main(){

    string ip_s, op_s = "";
    cout<<"Enter any two or more numbers from 0 to 9 (without spaces): ";
    cin>>ip_s;                      //23
    allWords_phnDigit(ip_s, op_s);  //"23", ""

    return 0;
}

/*-------------OUTPUT-------------
Enter any two or more numbers from 0 to 9 (without spaces): 23    
ad
ae
af
bd
be
bf
cd
ce
cf
*/