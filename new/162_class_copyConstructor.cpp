#include<iostream>
#include<string>
using namespace std;


class Number{
    
    private:
        int a;
        string s;

    public: 
        Number(int num = 0, string str="zero"){
            a = num;
            s = str;
        }
        
        // When no copy constructor is found, compiler supplies its own copy constructor
        Number(Number &obj){
            cout<<"--------Copy constructor called!--------"<<endl;
            a = obj.a;
            s = obj.s;
        }

        void display(){
            cout<<"The number for this object is "<< a <<endl;
            cout<<"The string for this object is "<< s <<endl;
        }

        bool operator == (Number &obj){
            if(this->a==obj.a && this->s==obj.s)
                return 1;
            else
                return 0;
        }
};
int main(){
    Number x, y(23, "twenty three"), z(45, "forty five"), z2;
    x.display();
    y.display();
    z.display();

    Number z1(z); // Copy constructor invoked, either we create or not it will work
    z1.display();

    z2 = z; // Copy constructor not called as z2 is declared earlier
    z2.display();

    Number z3 = z; // Copy constructor invoked, as it is declared as well as initialised by another object at the same time
    z3.display();

    //example of operator overloading as objects are being compared
    // == whcih are otherwise not allowed
    if (z1==z)  
        cout<<"both are same"<<endl;
    else
        cout<<"both are not same"<<endl;

    return 0;
}


// The number for this object is 0
// The string for this object is zero        
// The number for this object is 23
// The string for this object is twenty three
// The number for this object is 45
// The string for this object is forty five  
// --------Copy constructor called!--------  
// The number for this object is 45
// The string for this object is forty five  
// The number for this object is 45
// The string for this object is forty five  
// --------Copy constructor called!--------  
// The number for this object is 45
// The string for this object is forty five  
// both are same