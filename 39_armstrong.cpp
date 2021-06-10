// To write a program for checking if a number is a armstrong number or not.
// Eg - 153, 370, 371, 407 ---> cube(1)+cube(5)+cube(3) = 1+125+27 = 153.
// sum of cubes of all the digits of that number is equal to that number.

#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int n, cube_sum, lastdigit;
    cout<<"Enter the number for checking Armstrong or not: ";
    cin>>n;
    cube_sum = 0;
    int original_n = n;
    
    while(n>0){
        lastdigit = n%10;
        // cube_sum += (lastdigit*lastdigit*lastdigit);
        cube_sum += pow(lastdigit, 3);
        n=n/10;
    }
    if (original_n==cube_sum){
        cout<<cube_sum<<" is an Armstrong number!"<<endl;
    }
    else{
        cout<<original_n<<" is not an Armstrong number!"<<endl;
    }
    return 0;
}