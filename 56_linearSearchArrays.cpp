// To write a program ..Linear Search

#include <iostream>
using namespace std;

int main(){

    int n, key, flag=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<"Enter the element to be searched in array: ";
    cin>>key;
    for (int i = 0; i < 10; i++){
        if (a[i]==key){
            flag +=1; 
            cout<<"Key: "<<key<<" is present at index: "<<i<<endl;
        }
    }
    if (flag == 0){
        cout<<"Key: "<<key<<" is not present in array."<<endl;
    }
    return 0;
}