#include<iostream>
using namespace std;

// giving default data types  
template <class T1=int, class T2=float, class T3=char>
class Harry{
    private:
        T1 a;
        T2 b;
        T3 c;
    public:
        Harry(T1 x, T2 y, T3 z) {
            a = x;
            b = y;
            c = z;
        }
        void display(){
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
        }
};

int main()
{
    Harry<> h(4, 6.4, 'c'); //using the default ones
    h.display();
    cout << endl;
    Harry<float, char, char> g(1.6, 'o', 'c'); //using of our choice
    g.display();
    return 0;
}

// --------Output--------
// The value of a is 4
// The value of b is 6.4
// The value of c is c

// The value of a is 1.6
// The value of b is o
// The value of c is c