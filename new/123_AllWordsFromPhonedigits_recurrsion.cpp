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
    
    char ch = inp_s[0]; //this or we could have simply push_back this char into op_s2
    inp_s.erase(0,1);

    allWords_phnDigit(inp_s, op_s);
    allWords_phnDigit(inp_s, (op_s+ch) );

}



int main(){

    int k1, k2;
    cout<<"Press two keys from 0 to 9: ";
    cin>>k1>>k2;
    string ip_s = keyPad[k1] + keyPad[k2];
    // cout<<ip_s;
    string op_s = "";

    allWords_phnDigit(ip_s, op_s);
    return 0;
}

/*-------------OUTPUT-------------
Press two keys from 0 to 9: 1 2

c   
b   
bc  
a   
ac  
ab  
abc 
/   
/c  
/b  
/bc 
/a  
/ac 
/ab 
/abc
.   
.c  
.b  
.bc 
.a  
.ac 
.ab 
.abc
./  
./c 
./b 
./bc
./a
./ac
./ab
./abc
*/