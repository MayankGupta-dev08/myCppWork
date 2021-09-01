// C++ program to illustrate the use of sizeof, typedef and #define

// typedef: The typedef is used to give data type a new name.
// #define in C is a directive which is used to #define alias.

/*Difference between typedef and #define:
	1.	typedef is limited to giving symbolic names to types only, whereas #define can be used to define an alias for values as well, e.g., you can define 1 as ONE, 3.14 as PI, etc.
	2.	typedef interpretation is performed by the compiler where #define statements are performed by preprocessor.
	3.	#define should not be terminated with a semicolon, but typedef should be terminated with semicolon.
	4.	#define will just copy-paste the definition values at the point of use, while typedef is the actual definition of a new type.
	5.	typedef follows the scope rule which means if a new type is defined in a scope (inside a function), then the new type name will only be visible till the scope is there. In case of #define, when preprocessor encounters #define, it replaces all the occurrences, after that (No scope rule is followed).*/

#include<iostream>
using namespace std;

typedef float FLOAT; 
#define pi 3.14

int main()
{
	cout << "Size of bool : " << sizeof(bool)<< " bytes" <<endl;
	cout << "Size of char : " << sizeof(char)<< " byte" << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t)<< " bytes" <<endl;
	cout << "Size of short int : " << sizeof(short int)<< " bytes" << endl;
	cout << "Size of int : " << sizeof(int)<< " bytes" << endl;
	cout << "Size of long int : " << sizeof(long int)<< " bytes" << endl;
	cout << "Size of float : " << sizeof(FLOAT)<< " bytes" <<endl;
	cout << "Size of double : " << sizeof(double)<< " bytes" << endl;
	cout << "Size of signed long int : " << sizeof(signed long int)<< " bytes" << endl;
	cout << "Size of unsigned long int : " << sizeof(unsigned long int)<< " bytes" <<endl<< endl;
	
	cout<<pi<<endl;

	return 0;
}
