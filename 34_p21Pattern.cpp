/* To write a program to print Pallindromic Pattern
Enter the numbers of rows: 5

        1
      2 1 2
    3 2 1 2 3
  4 3 2 1 2 3 4 
5 4 3 2 1 2 3 4 5

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
        // for (int j = 1; j <= r-i; j++){
        //     cout<<"  ";
        // }
        // if (i>=2){
        //     for (int j = i; j >= 2; j--)
        //     {
        //         cout<<j<<' ';
        //     }
        // }
        // for (int j = 1; j <= i; j++){
        //     cout<<j<<' ';
        // }
        
        for (int j = 1; j <= r-i; j++){
            cout<<"  ";
        }
        for (int j = i; j >= 1; j--){
            cout<<j<<' ';
        }
        for (int j = 2; j <= i; j++){
            cout<<j<<' ';
        }     
        
        cout << endl;
    }

    return 0;
}