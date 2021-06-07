/* To write a program to print the following pattern
Enter the numbers of rows: 5

1  
2  3  
3  4  5  
4  5  6  7  
5  6  7  8  9 

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
        for (int j = 0; j < i; j++)
        {
            cout<<j+i<<"  ";
        }
        cout << endl;
    }

    return 0;
}