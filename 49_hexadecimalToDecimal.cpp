// To write a program to print Decimal (0,1,2,3,4,5,6,7,8,9) from Hexadecimal (0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F)

#include <iostream>
#include <string>
using namespace std;

int hexadecimalToDecimal(string n){
    int result = 0, sixteen = 1;
    int s = n.length();
    // int s = n.size();
    // Both string.size() and string.length() returns length without including null char.

    for (int i = s-1; i>=0; i--){
        
        if (n[i]>='0' && n[i]<='9'){    // digits will also be considerred in char since comming from string.
            result += sixteen*(n[i]-'0');
        }
        else if (n[i]>='A' && n[i]<='F'){
            result += sixteen*((n[i]-'A') + 10);    // if 'a'-'a' --> 0 as it subtracts ASCII value of each char.
        }
        sixteen *= 16;
    }
    return result;
}

int main(){
    string n;
    cin>>n;

    cout<<hexadecimalToDecimal(n)<<endl;
    return 0;
}