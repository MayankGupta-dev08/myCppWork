/* To write a program to print FLoyds Triangle
Enter the numbers of rows: 5

1
2  3
4  5  6
7  8  9  10
11 12 13 14 15

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