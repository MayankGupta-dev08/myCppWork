//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*Important ASCII VALUES
    0 --> 48 AND 9 --> 57   //10 NUMBERS
    A --> 65 AND Z --> 90   //26 ALPHA
    a --> 97 AND z --> 122   //26 ALPHA
*/

int main(){
    int intarr1[] = {'f', 'g'+3, 'h'};
    char chararr[] = {'5', '6', '7'};
    int i=0;
    while(i<3){
        intarr1[i] = intarr1[i] + intarr1[i];
        intarr1[i] = intarr1[i] + chararr[i];
        cout<<intarr1[i]<<endl;
        i++;
    }
    
    cout<<endl;
    i=0;
    int intarr2[] = {'f', 'g'+'3', 'h'};
    while(i<3){
        intarr2[i] = intarr2[i] + intarr2[i];
        intarr2[i] = intarr2[i] + chararr[i];
        cout<<intarr2[i]<<endl;
        i++;
    }
    return 0;
}

// 257
// 266
// 263
// 
// 257
// 362
// 263