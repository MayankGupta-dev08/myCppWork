// To write a program ..
/* INVERTED HALF PYRAMID
Enter the numbers of rows: 8

********
*******
******
*****
****
***
**
*

*/

#include <iostream>
using namespace std;

// int main(){

//     int r;
//     cout<<"Enter the numbers of rows: ";
//     cin>>r;
//     int count = r;

//     for(int i=1; i<=r; i++){
//         for (int j = count; j >= 1; j--)
//         {
//             cout<<'*';
//         }
//         count -=1;
//         cout<<endl;
//     }

//     return 0;
// }

int main()
{

    int r;
    cout << "Enter the numbers of rows: ";
    cin >> r;

    for (int i = r; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}