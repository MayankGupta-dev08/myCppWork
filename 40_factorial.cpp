// To write a program for printing factorial of a number.

#include <iostream>
using namespace std;

int main()
{

    int n, fact;
    cout<<"Enter the number for finding factorial: ";
    cin>>n;
    fact = 1;
    
    for(int i =1; i<=n; i++){
        fact *= i;
    }
    cout<<"Factoral of "<<n<<" is: "<<fact<<endl;
    return 0;
}