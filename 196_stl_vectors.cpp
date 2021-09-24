// Initialize a vector in C++ (6 different ways)

#include <bits/stdc++.h>
using namespace std;

void method1(){
    //  Initializing by pushing values one by one :
 
    vector<int> vect;   // Create an empty vector
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
 
    for (int x : vect)
        cout << x << " ";
    cout<<endl;
}

void method2(){
    // Specifying size and initializing all values :

    int n = 3;
    vector<int> vect(n, 10);    // Create a vector of size n with all values as 10.
 
    for (int x : vect)
        cout << x << " ";
    cout<<endl;
}

void method3(){
    // Initializing like arrays :

    vector<int> vect{ 10, 20, 30 };
    for (int x : vect)
        cout << x << " ";
    cout<<endl;
}

void method4(){
    // Initializing from an array :

    int arr[] = { 10, 20, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    vector<int> vect(arr, arr + n);
 
    for (int x : vect)
        cout << x << " ";
    cout<<endl;
}

void method5(){
    // Initializing from another vector :

    vector<int> vect1 {11,12,13,14};
    vector<int> vect2 (vect1.begin(), vect1.end());
    for (int x : vect2)
        cout << x << " ";
    cout<<endl;
}

void method6(){
    // Initializing all elements with a particular value :

    vector<int> vect1(10);  //10 will be the size of vect1
    int val = 0;
    fill(vect1.begin(), vect1.end(), val);
    for (int x : vect1)
        cout << x << " ";
    cout<<endl;
}

int main()
{
    method1();
    method2();
    method3();
    method4();
    method5();
    method6();
 
    return 0;
}


/* 
10 20 30 
10 10 10 
10 20 30 
10 20 30 
11 12 13 14 
0 0 0 0 0 0 0 0 0 0 
 */