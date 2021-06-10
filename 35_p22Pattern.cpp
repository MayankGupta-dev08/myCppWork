/* To write a program to print Kite Pattern
Enter the numbers of rows: 5

        *
      * * *
    * * * * *
  * * * * * * * 
* * * * * * * * *
* * * * * * * * *
  * * * * * * * 
    * * * * *
      * * *
        *

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
        for (int j = 1; j <= r-i; j++){
            cout<<"  ";
        }
        for (int j = 1; j <= (2*i)-1; j++){
            cout<<"* ";
        }
        cout << endl;
    }

    for (int i = r; i >= 1; i--)
    {
        for (int j = 1; j <= r-i; j++){
            cout<<"  ";
        }
        for (int j = 1; j <= (2*i)-1; j++){
            cout<<"* ";
        }
        cout << endl;
    }
    return 0;
}