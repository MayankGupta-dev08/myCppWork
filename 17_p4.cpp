// Understanding Post and Pre increment ..
// Pre increment - fisrt increase and then use.
// Post increment - fisrt use and then increase before the next operation.

#include <iostream>
using namespace std;

int main()
{

    int i = 1;
    int j = 2;
    int k;

    //  1 + 2 + 1   +  2  +  3  +   4
    k = i + j + i++ + j++ + ++i + ++j;

    //       3               4               13
    cout << "i: " << i << ", j: " << j << ", k: " << k << endl;

    return 0;
}