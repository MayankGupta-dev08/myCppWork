// Earlier we have studied that with the help of classes we create a type of template which we can use for multiple objects. So for objects, a class is a template.
// But for creating multiple classes with some different property (data type) doing same thing we have Templates in C++
// templates in C++ are also known as Parameterised classes
//  Why Templates - 
        // DRY principles
        // Generic programming
/*
A template is a simple and yet very powerful tool in C++. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need sort() for different data types. Rather than writing and maintaining the multiple codes, we can write one sort() and pass data type as a parameter. 
C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by keyword ‘class’.

#include <iostream>
using namespace std;
 
template <class T>
class vector {
    T *arr;
    int size;
    public:
        vector(T* arr)[
            //code
        ]
        //and many other methods
    
};
 
int main() {
    vector<int> myVec1();
    vector<float> myVec2();
    return 0;
}
*/

#include <iostream>
using namespace std;

template <class T> 
class vector{

    private:
        T *arr;
        int size;

    public:
        vector(int m){
            size = m;
            arr = new T[size];
        }
        
        void setValues(){
            cout<<"Enter "<<size<<" values for your vector."<<endl;
            for (int i = 0; i < size; i++){
                cin>>arr[i];
            }
        }

        T dotProduct(vector &v){
            T d=0;
            for (int i = 0; i < size; i++){
                d += this->arr[i]*v.arr[i];
            }
            return d;
        }
};
 
int main()
{
    vector<int> v1(3); //vector 1
    v1.setValues();
    vector<int> v2(3); //vector 2
    v2.setValues();
    cout<<"Dot product of the vector v1 and v2 are: "<<v1.dotProduct(v2)<<endl<<endl;

// Using the same class for a float type data members without much of work
    vector<float> v3(4); //vector 3
    v3.setValues();
    vector<float> v4(4); //vector 4
    v4.setValues();
    cout<<"Dot product of the vector v3 and v4 are: "<<v3.dotProduct(v4)<<endl;

    return 0;
}

// ------------------Output------------------
// Enter 3 values for your vector.
// 4 1 3
// Enter 3 values for your vector.
// 1 0 1
// Dot product of the vector v1 and v2 are: 7

// Enter 4 values for your vector.
// 1.1 2.3 4.3 2.2
// Enter 4 values for your vector.
// 2 .1 2.3 3.5
// Dot product of the vector v3 and v4 are: 20.02