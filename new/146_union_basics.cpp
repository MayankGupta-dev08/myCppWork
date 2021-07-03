/*
Unions: A union is a type of structure that can be used where the amount of memory used is a key factor. 

1.  Similarly to the structure, the union can contain different types of data types. 
2.  Each time a new variable is initialized from the union it overwrites the previous in C language but in C++ we also don’t need this keyword and uses that memory location. 
3.  This is most useful when the type of data being passed through functions is unknown, using a union which contains all possible data types can remedy this problem. 
4.  It is declared by using the keyword “union“.
5.  the size of the union datatype will be max of all the data members.
*/

#include <iostream>
using namespace std;

// Declaration of union is same as structures
union test {
	int x, y;
};

union test2{
    int v1;
    char v2;
    float v3;
};

int main()
{
	// A union variable t of test
	union test t;
	t.x = 2; // t.y also gets value 2
	cout<<"After making x = 2"<<endl<<t.x<<", "<<t.y<<endl;
	t.y = 10; // t.x is also updated to 10
	cout<<"After making y = 10"<<endl<<t.x<<", "<<t.y<<endl<<endl;;
	

	// A union variable tt of test2
	union test2 tt;
	tt.v1 = 65;
	cout<<"After making v1 = 65 --->\t"<<tt.v1<<", "<<tt.v2<<", "<<tt.v3<<endl;
	cout<<"sizeof(tt): "<<sizeof(tt)<<endl; 
	tt.v2 = 67; 
	cout<<"After making v2 = 67 --->\t"<<tt.v1<<", "<<tt.v2<<", "<<tt.v3<<endl;
	cout<<"sizeof(tt): "<<sizeof(tt)<<endl; 
	tt.v3 = 68.5;
	cout<<"After making v3 = 68.5 --->\t"<<tt.v1<<", "<<tt.v2<<", "<<tt.v3<<endl;
	cout<<"sizeof(tt): "<<sizeof(tt)<<endl; 

	return 0;
}
