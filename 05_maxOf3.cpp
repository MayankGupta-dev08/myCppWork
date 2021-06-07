#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    // Code for max of three numbers
    int a,b,c;
    cout<<"For finding max of three numbers\n";
    cin>>a>>b>>c;

    int max=a;
    if (b>max){
        if (b>c){
            cout<<"Max is: "<<b;
        }
        else{
            cout<<"Max is: "<<c;
        }     
    }
    else{
        if (a>c){
            cout<<"Max is: "<<a;
        }
        else{
            cout<<"Max is: "<<c;
        }
    }

    return 0;
}