/* To write a program to print Number Pattern
Enter the numbers of rows: 5

    1 
   1 2
  1 2 3
 1 2 3 4 
1 2 3 4 5

*/

#include <iostream>
using namespace std;

int main()
{

    int r;
    cout << "Enter the numbers of rows: ";
    cin >> r;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= r-i; j++)
        {
            cout<<' ';
        }
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<' ';
        }
        cout << endl;
    }

    return 0;
}