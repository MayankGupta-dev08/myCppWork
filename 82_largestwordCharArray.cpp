// To write a program ..

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    char arr [n+1];
    
    // for (int i = 0; i < n; i++){
    //     cin>>arr;
    // }
    // As the above line does not consider space as a function.

    cin.ignore();
    cin.getline(arr, n+1);
    // cin.ignore();

    for(int i = 0; arr[i]!='\0'; i++)
        cout<<arr[i];

    cout<<endl;
    int i = 0, currLength=0, maxLength=0;
    int st_pt = 0, end_pt = 0;

    while(true){
        
        if (arr[i]==' ' || arr[i]=='\0'){
            currLength=0;
            if(arr[i]=='\0'){
                break;
            }
        }
        else{
            currLength++;
            if (maxLength<currLength){
                maxLength = currLength;
                end_pt=i;
            }
        }
        i++;
    }
    // here we are printing indices starting from 0.
    st_pt = end_pt-maxLength-1;
    cout<<st_pt<<endl<<end_pt<<endl;
    cout<<"Length of max word: "<<maxLength<<endl;
    for (int i = st_pt; i <= end_pt; i++){
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}