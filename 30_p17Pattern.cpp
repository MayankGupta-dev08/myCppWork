/* To write a program to print 0-1 Pattern
Enter the numbers of rows: 5

1                               (1,1)                           Considering
0 1                             (2,1) (2,2)                         i+j 
1 0 1                           (3,1) (3,2) (3,3)                   Even --> 1
0 1 0 1                         (4,1) (4,2) (4,3) (4,4)             Odd  --> 0
1 0 1 0 1                       (5,1) (5,2) (5,3) (5,4) (5,5)

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
        for (int j = 1; j <= i; j++)
        {
            if ((i+j)%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout << endl;
    }

    return 0;
}