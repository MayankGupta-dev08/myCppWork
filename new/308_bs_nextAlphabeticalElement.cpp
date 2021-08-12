/*Given an array of letters sorted in ascending order, find the smallest letter in the the array which is greater than a given key letter.*/

#include <iostream>
using namespace std;

char nextAplhabet(char arr[], int n, char key){
    int start=0, end=n-1;
    char ans = 'z';
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return key+1;
        
        if(arr[mid]<key)
            start=mid+1;

        else if(arr[mid]>key){
            ans=min(ans,arr[mid]);
            end=mid-1;
        }
    }
    if(ans=='z')
        return '*';
    else
        return ans;
}

int main(){
    char arr[] = {'a','c','f','h'};
    int n = sizeof(arr)/sizeof(arr[0]);
    char key = 'f';
    char ans = nextAplhabet(arr,n,key);
    if (ans=='z')
        cout<<"next alphabet doesn't exist!\n";
    else
        cout<<"the next alphabet of "<<key<<" is: "<<ans<<endl;

    key = 'b';
    ans = nextAplhabet(arr,n,key);
    if (ans=='z')
        cout<<"next alphabet doesn't exist!\n";
    else
        cout<<"the next alphabet of "<<key<<" is: "<<ans<<endl;
    return 0;
}

// the next alphabet of f is: g
// the next alphabet of b is: c