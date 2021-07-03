// To write a program ..to show the use of class template with multiple parameters in c++
// template <class T1, class T2, class T3,.............>

//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

template <class t1, class t2>
class myClass{

    private:
        t1 data1;
        t2 data2;
    public:
        myClass(t1 d1, t2 d2){
            data1 = d1;
            data2 = d2;
        }

        void display(){
            cout<<"Data1: "<<data1<<endl;
            cout<<"Data2: "<<data2<<endl;
            cout<<"---------------------"<<endl;
        }
};

int main(){

    myClass<float, int> obj1(9.8, 133);
    obj1.display();

    myClass<char, int> obj2('m', 1);
    obj2.display();
    
    myClass<float, char> obj3(8.4, 'g');
    obj3.display();
    
    myClass<float, string> obj4(8, "mannu");
    obj4.display();
    
    return 0;
}

// *******OUTPUT*******
// Data1: 9.8
// Data2: 133
// ---------------------
// Data1: m
// Data2: 1
// ---------------------
// Data1: 8.4
// Data2: g
// ---------------------
// Data1: 8
// Data2: mannu
// ---------------------