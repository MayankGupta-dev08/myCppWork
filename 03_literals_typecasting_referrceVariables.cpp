// *************some predefined header files*************
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<iomanip>

//*************user defined header file************* 
#include "myHeader.h"   //this will throw an error if the file is not in same directory
// this will only work if it is in the same current working directory 

using namespace std;

int c = 45;     // global variable

int main(){
    
    // *************Build in Data types****************
    // int a, b, c;
    // cout<<"Enter the value of a:"<<endl;
    // cin>>a;
    // cout<<"Enter the value of b:"<<endl;
    // cin>>b;
    // c = a + b;
    // cout<<"The sum is "<<c<<endl;
    // cout<<"The global c is "<<::c;

    // ************* Float, double and long double Literals****************
    float d=34.4F;
    long double e = 34.4L; 
    cout<<"The size of 34.4 is "<<sizeof(34.4)<<endl;
    cout<<"The size of 34.4f is "<<sizeof(34.4f)<<endl;
    cout<<"The size of 34.4F is "<<sizeof(34.4F)<<endl;
    cout<<"The size of 34.4l is "<<sizeof(34.4l)<<endl;
    cout<<"The size of 34.4L is "<<sizeof(34.4L)<<endl;
    cout<<"The value of d is "<<d<<endl<<"The value of e is "<<e;  

    // *************Reference Variables**************** 
    // Rohan Das----> Monty -----> Rohu ------> Dangerous Coder
    //just like that we can give many names to a single varibale and call it using them

    float x = 455;
    float & y = x;   // now we can call x using y also
    float *z = &x;   //creating a pointer z which is pointing at x and has address of x

    cout<<x<<endl;
    cout<<y<<endl;

    // *************Typecasting**************** 
    int a = 45;   
    float b = 45.46;
    cout<<"The value of a is "<<(float)a<<endl;
    cout<<"The value of a is "<<float(a)<<endl;

    cout<<"The value of b is "<<(int)b<<endl;
    cout<<"The value of b is "<<int(b)<<endl;
    int c = int(b);

    cout<<"The expression is "<<a + b<<endl;
    cout<<"The expression is "<<a + int(b)<<endl;
    cout<<"The expression is "<<a + (int)b<<endl;


    return 0;
}
