// To write a program ..
/* HOLLOW RECTANGULAR PATTERN
Enter the numbers of rows: 8
Enter the numbers of columns: 6
******
*    *
*    *
*    *
*    *
*    *
*    *
******
*/

#include <iostream>
using namespace std;

int main(){

    int r,c;
    cout<<"Enter the numbers of rows: ";
    cin>>r;
    cout<<"Enter the numbers of columns: ";
    cin>>c;
    
    for(int i=1; i<=r; i++){
        for (int j = 1; j <= c; j++)
        {
            if (i==1 || j==1 || i==r || j==c){
                cout<<'*';
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}