// function call operator overloading

#include <iostream>
using namespace std;

class sample{
    private:
        int a, b, c;

    public:
        sample(){           //Default constructor
            cout<<"Default constructor is called\n";
            a=0, b=0, c=0;
        }

        sample(int x, int y, int z){    //Parameterised constructor
            cout<<"Parameterised constructor is called\n";
            a=x, b=y, c=z;
        }

        void operator()(int p, int q, int r){
            cout<<"Function call() operator overloading is called.\n";
            a=p, b=q, c=r;
        }

        void showData(){
            cout<<a<<" "<<b<<" "<<c<<" "<<endl;
        }
};

int main(){
    sample s1;
    s1.showData();
    
    sample s2(1,2,3);
    s2.showData();
    
    sample s3;
    s3(10,20,30);  // if function call operator was not there then error would have occured
    s3.showData();
    return 0;
}

// Default constructor is called
// 0 0 0 
// Parameterised constructor is called
// 1 2 3 
// Default constructor is called
// Function call() operator overloading is called.
// 10 20 30 