// Understanding Post and Pre increment ..
// Pre increment - fisrt increase and then use.
// Post increment - fisrt use and then increase before the next operation.

#include <iostream>
using namespace std;

int main()
{

    int i = 0;
    
    //  0   -   0  +  1 -  1
    i = i++ - --i + ++i - i--;
    
    //      0
    cout << i << endl;

    return 0;
}