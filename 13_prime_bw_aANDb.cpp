// Print whether all prime numbers between a range of two numbers given by users.

#include <iostream>
#include<cmath>
using namespace std;

// int main(){
//     int a, b, flag;
//     cout << "Enter lower value of range: ";
//     cin >> a;
//     cout << "Enter lower value of range: ";
//     cin >> b;
//     cout << "All prime numbers from " << a << " to " << b << " are:\n";

//     for (int num = a; num <= b; num++){
//         if (num < 2){
//             continue;
//         }
//         flag = 0;
//         for (int i = 2; i < num; i++){
//             if (num % i == 0){
//                 flag += 1;
//                 break;
//             }
//         }
//         if (flag == 0){
//             cout << num << " ";
//         }
//     }

//     cout << endl;
//     return 0;
// }

bool primeCheck(int n){
    for(int i=2; i<= pow(n, 0.5); i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void a_prime_b(int a, int b){
    for (int i = a; i <= b; i++){
        if(i<2)
            continue;
        if(primeCheck(i)){
            cout<<i<<" ";
        }
    }
}

int main(){
    int a,b;
    cout<<"Enter the values of a and b: ";
    cin>>a>>b;
    a_prime_b(a,b);
    cout<<endl;
    return 0;
}