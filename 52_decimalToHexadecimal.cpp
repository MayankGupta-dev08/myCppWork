// To write a program to conert Decimal (0,1,2,3,4,5,6,7,8,9) HEXADECIMAL (0,1,2,3,4,5,6,7,8,9,A,B,C,D,E)

#include<bits/stdc++.h>
using namespace std;

string decimalToHexadecimal(int n){     //n=100
    int x=1;
    string ans = "";
    while(x<=n){
        x *= 16;
    }
    x /= 16;                    //x=96, pow(16,6)
    while(x>0){
        int lastdigit = n/x;    //lastdigit=1
        n -= lastdigit*x;       //n=4
        x /= 16;                //x=80

        if(lastdigit<=9){
            ans = ans + to_string(lastdigit);
        }
        else{                   //here last digit will be >=10 and <=15
            char c = 'A' + (lastdigit-10);
            ans.push_back(c);            //appending a single char in string.
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<decimalToHexadecimal(n)<<endl;
    return 0;
}