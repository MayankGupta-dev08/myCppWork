/*Static variables are class variables.
Every object of class have its own copy of variables but im case of static variables... Value of static variable is not different for different objects.

Static functions can access only static variables of their class and not other data members.
These functions are accessed by class only and not objects.
Employee :: getCount();

Static local variable = class variables
Visibility: class
Lifetime: till termination of program
Default value:0
Storage:heap

Local Variable
Visibility: class
Lifetime: until execution of class
Default value:garbage
Storage:stack

Global variable
Visibility: file
Lifetime: till termination of program
Default value:0
Storage:heap
*/

#include <iostream>
using namespace std;

class Employee
{
    int id;
    static int count;   //it will be initialised only once as the first object of this class is created and it will not be initialized again like others rather it will continue from the same value last left by some other object.

public:
    void setData(void)
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of this employee is " << id << " and this is employee number " << count << endl;
    }

    static void getCount(void){
        // cout<<id; // throws an error
        cout<<"The value of count is "<<count<<endl;
    }
};

// Count is the static data member of class Employee
int Employee::count; 
// Default value is 0, but if we want we can set an initial value, here only (outside class). 

int main()
{
    Employee harry, rohan, lovish;
    // harry.id = 1;
    // harry.count=1; // cannot do this as id and count are private

    harry.setData();
    harry.getData();
    Employee::getCount();

    rohan.setData();
    rohan.getData();
    Employee::getCount();

    lovish.setData();
    lovish.getData();
    Employee::getCount();

    return 0;
}
