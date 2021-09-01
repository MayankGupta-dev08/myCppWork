
#include <iostream>
#include <string>
using namespace std;

int KthNonRepeatingChar(string s, int k){
    int arr[127];
    for (int i = 0; i < 127; i++)
        arr[i] = -1;
    
    for(int i=0; i<s.length(); i++)
        arr[int(s[i])]++;

    int flag=0;
    for(int i=0; i<127; i++){
        if(arr[i]==0){
            flag++;
            if(flag==k)
                return i; 
        }
    }
    return -1;
}

int main(){
    string s = "geeksforgeeks";
    int k=2;
    int res = KthNonRepeatingChar(s,k); 
    if(res!=-1)
    cout<<k<<"th non repeating element: "<<char(res)<<endl;
    else    
        cout<<k<<"th non repeating element not present.\n";

    
    k=3, res = KthNonRepeatingChar(s,k); 
    if(res!=-1)
    cout<<k<<"th non repeating element: "<<char(res)<<endl;
    else    
        cout<<k<<"th non repeating element not present.\n";
    return 0;
}

// 2th non repeating element: o
// 1th non repeating element: f
// 3th non repeating element: r