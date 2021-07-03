// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    // input    - pippppiiiipi
    // output   - 3.14ppp3.14iii3.14

    // input    - pippxxppiixipi
    // output   - 3.14ppxxp3.14ixi3.14

    string str ="pippxxppiixipi";
    for (int i = 0; i < str.length()-1; i++){
        string st = str.substr(i,2);
        if(st.compare("pi")==0){
            str.erase(i, 2);
            str.insert(i, "3.14");
            i=i+3;
        }
    }
    cout<<str<<endl;
    return 0;
}