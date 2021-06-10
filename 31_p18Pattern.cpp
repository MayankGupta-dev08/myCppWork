/* To write a program to print Rhombus Pattern
Enter the numbers of rows: 5

        * * * * *
      * * * * *
    * * * * *
  * * * * *
* * * * *

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
        for (int j = 1; j <= (r+(r-i)); j++)
        {
            if (j<=(r-i)){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout << endl;
    }

    return 0;
}