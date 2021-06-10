// To write a program ..

#include <iostream>
using namespace std;

void fib(int n){
    if (n==0){
        cout<<' ';
        return;
    }
    int t1=0;
    int t2=1;
    int nextTerm;
    for (int i=1; i<=n;i++){
        cout<<t1<<' ';
        nextTerm = t1+t2;
        t1 = t2;
        t2 = nextTerm;
    }

}

int main(){

    int a;
    cout<<"Enter the number of terms in series to be printed: ";
    cin>>a;
    fib(a);
    cout<<endl;
    return 0;
}