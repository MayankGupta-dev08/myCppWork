// To write a program ..
/* 180 degree rotation of INVERTED HALF PYRAMID
Enter the numbers of rows: 8

       *
      **
     ***
    ****
   *****
  ******
 *******
********

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
        for (int j = 1; j <= r; j++)
        {
            if (j<=r-i){
                cout<<' ';
            }
            else{
                cout << '*';
            }    
        }
        cout << endl;
    }

    return 0;
}