/* To write a program to print Butterfly's Pattern
Enter the numbers of rows: 4

*             *
* *         * *
* * *     * * *
* * * * * * * *
* * * * * * * *
* * *     * * *
* *         * *
*             *

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
        for (int j = 1; j <= 2 * r; j++)
        {
            if (j <= i || j > ((2 * r) - i))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    for (int i = r; i >= 1; i--)
    {
        for (int j = 1; j <= 2 * r; j++)
        {
            if (j <= i || j > ((2 * r) - i))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}