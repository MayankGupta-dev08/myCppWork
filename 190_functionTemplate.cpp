// To write a program ..to show the use of function template

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <class t1, class t2>
t1 funcAvg(t1 a, t2 b){
    return ((a+b)/2);
}

template <class T>
void swapping(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

int main(){

    int a,b;
    cout<<"Enter two integers for finding avg: ";
    cin>>a>>b;
    cout<<"Avg of the two integers: "<<funcAvg(a,b)<<"\t-> As return type was int"<<endl
        <<"---------------------------------------\n";
    
    int c;
    float d;
    cout<<"Enter two integers for finding avg: ";
    cin>>c>>d;
    cout<<"Avg of the an integer and a float: "<<funcAvg(c,d)<<"\t-> As return type was int"<<endl
        <<"---------------------------------------\n";
    
    float e,f;
    cout<<"Enter two integers for finding avg: ";
    cin>>e>>f;
    cout<<"Avg of the two floats: "<<funcAvg(e,f)<<"\t-> As return type was float"<<endl
        <<"---------------------------------------\n";
    
    char c1, c2;
    cout<<"Enter two chars for swapping them: ";
    cin>>c1>>c2;
    cout<<"Before swapping: c1="<<c1<<" and c2="<<c2<<endl;
    swapping(c1,c2);
    cout<<"After swapping: c1="<<c1<<" and c2="<<c2<<endl;

    return 0;
}

// Output
// Enter two integers for finding avg: 5 2
// Avg of the two integers: 3      -> As return type was int
// ---------------------------------------
// Enter two integers for finding avg: 5 2
// Avg of the an integer and a float: 3    -> As return type was int  
// ---------------------------------------
// Enter two integers for finding avg: 5 2
// Avg of the two floats: 3.5      -> As return type was float
// ---------------------------------------
// Enter two chars for swapping them: 5 2
// Before swapping: c1=5 and c2=2
// After swapping: c1=2 and c2=5