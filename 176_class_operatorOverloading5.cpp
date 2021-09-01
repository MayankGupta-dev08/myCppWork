// arrow operator overloading

#include <iostream>
using namespace std;

class sample{
    private:
        int a;

    public:
        sample(){
            a=10;
        }

        void showData(){
            cout<<a<<endl;
        }

        sample* operator -> (){
            cout<<"arrow operator overloading function\n";
            return this;        //return the same object who has called this
        }
};

int main(){
    sample s1;
    s1.showData();
    s1->showData(); //if now arrow operator overloading function exists than error
    
    return 0;
}

// 10
// arrow operator overloading function
// 10