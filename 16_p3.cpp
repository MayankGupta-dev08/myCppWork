// Understanding Post and Pre increment ..
// Pre increment - fisrt increase and then use.
// Post increment - fisrt use and then increase before the next operation.

#include <iostream>
using namespace std;

int main()
{

    int a = 1;
    //  1 ->2->++2=3
    //  1   +   3
    a = a++ + ++a;
//  4
    cout << a << endl;

    return 0;
}