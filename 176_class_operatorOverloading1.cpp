// In C++, we can make operators to work for user defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading.

// Operator functions are same as normal functions. The only differences are, name of an operator function is always operator keyword followed by symbol of operator and operator functions are called when the corresponding operator is used.

// Syntax:
    // ClassName operator + (ClassName const &ob_rhs)
    // ClassName operator - (ClassName const &ob_rhs)
    // ClassName operator * (ClassName const &ob_rhs)
    // ClassName operator / (ClassName const &ob_rhs)

#include<iostream>
using namespace std;

class Complex {
private:
	int real, imag;
public:
	Complex(int r = 0, int i =0){
        real = r; imag = i;
    }
	
	// This is automatically called when '+' is used with b/w two Complex objects
	Complex operator + (Complex const &obj_rhs) {
		Complex res1;
		res1.real = real + obj_rhs.real;
		res1.imag = imag + obj_rhs.imag;
		return res1;
	}
	
    // This is automatically called when '+' is used with b/w two Complex objects
	Complex operator - (Complex const &obj_rhs) {
		Complex res2;
		res2.real = real - obj_rhs.real;
		res2.imag = imag - obj_rhs.imag;
		return res2;
	}
	
    void print() { cout << real << " + i" << imag << endl; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	
    Complex c3 = c1 + c2; // An example call to "operator+"
	c3.print();

    Complex c4 = c1 - c2; // An example call to "operator+"
    c4.print();
}

// ----Output---
// 12 + i9
// 8 +i1