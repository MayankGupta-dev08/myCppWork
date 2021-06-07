// Understanding Post and Pre increment ..
// Pre increment - fisrt increase and then use.
// Post increment - fisrt use and then increase before the next operation.

#include <iostream>
using namespace std;

int main()
{

    int i = 1, j=2, k=3, m;
    
    //  1  -  2   -  3
    m = i-- - j-- - k--;
    
    cout  << "i: " << i << endl;  //0
    cout  << "j: " << j << endl;  //1
    cout  << "k: " << k << endl;  //2
    cout  << "m: " << m << endl;  //-4

    return 0;
}