// To write a program ..Check for pythagorain triplet

// #include<bits/stdc++.h>
#include <iostream>
using namespace std;

bool pytrip(int a,int b,int c){
    int x,y,z;
    x = max(a, max(b,c));
    if (x==a){
        y=b;
        z=c;
    }
    else if(x==b){
        y=a;
        z=c;
    }
    else{
        y=b;
        z=a;
    }
    
    if (x*x == y*y + z*z){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    int a,b,c;
    bool result;
    cin>>a>>b>>c;
    result = pytrip(a,b,c);
    if (result){
        cout<<"Yes, a Pyhtagorian Triplet!!";
    }
    else{
        cout<<"No, not a Pyhtagorian Triplet!!";
    }
    cout<<endl;
    return 0;
}