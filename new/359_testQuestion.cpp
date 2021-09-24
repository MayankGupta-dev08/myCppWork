//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

char* solve(char *str){
    char *res;
    int arr[128] = {0};
    for (int i = 0; str[i] != '\0'; i++)
        arr[str[i]]++;

    int freq;
    for (int i = 128-1; i >=0; i--){
        if(arr[i]!=0){
            freq = arr[i];
            break;
        }
    }
    
    char c;
    for (int i = 0; i < 128; i++){
        if(arr[i]!=0){
            c = char(i);
            break;
        }
    }

    char ans[freq];
    for (int i = 0; i < freq; i++){
        ans[i] = c;
    }
    res = ans;
    
    return res;
}

int main(){
    char str[30];
    cin>>str;
    cout<<solve(str)<<endl;
    return 0;
}

// input
    // ABCHjasdtdttc 
// output
    // AAA 