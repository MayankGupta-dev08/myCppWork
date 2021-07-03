// To write a program ..from a numeric string find the max possible number and print it.

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string s = "381290312038198";
    sort(s.begin(), s.end(), greater<int>());
    cout<<s<<endl;

    return 0;
}