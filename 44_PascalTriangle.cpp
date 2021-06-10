/* To write a program to print Pascal Triangle,
where elements are in form of nCr starting from i=0,j=0 to i=n-1 and j=n-1

        For n=8
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
1 7 21 35 35 21 7 1 

*/

#include <iostream>
using namespace std;

long fact(int num){
    if (num<=0 || num==1){
        return 1;
    }
    else{
        return num*fact(num-1);
    }
}

int main(){

    int n;
    cout<<"Enter the number rows for Pascal Triangle: ";
    cin>>n;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            cout<<(fact(i)/(fact(j)*fact(i-j)))<<' ';
        }
        cout<<endl;
    }
    return 0;
}