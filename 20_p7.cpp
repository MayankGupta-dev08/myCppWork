// Understanding Post and Pre increment ..
// Pre increment - fisrt increase and then use.
// Post increment - fisrt use and then increase before the next operation.

#include <iostream>
using namespace std;

int main()
{

    int i = 10, j=20, k;
    
    //  10  -  9  +  19 -  20  +  9  -  20 +  10 -  19
    k = i-- - i++ + --j - ++j + --i - j-- + ++i - j--;
    
    cout  << "i: " << i << endl;  //10
    cout  << "j: " << j << endl;  //18
    cout  << "k: " << k << endl;  //0

    return 0;
}