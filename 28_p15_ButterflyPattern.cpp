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
    int sum = 0;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            sum += 1;
            cout<<sum<<' ';
        }
        cout << endl;
    }

    return 0;
}