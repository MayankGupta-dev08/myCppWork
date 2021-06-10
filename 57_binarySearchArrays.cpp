// To write a program ..Binary Search
// Remember we should have a sorted array in increasing order fro this.
// This we will see after few programs.

#include <iostream>
using namespace std;

int binarySearch(int n, int a[], int key){
    int start = 0, end = n;
    while(start<=end){
        int mid = (start+end)/2;
        if (a[mid]==key){
            return mid;
        }
        else if (a[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){

    int n, key, flag;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];

    cout<<"Enter the elements of array\n";
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<"Enter the element to be searched in array: ";
    cin>>key;

    flag = binarySearch(n, a, key);
    
    if (flag == -1){
        cout<<"Key: "<<key<<" is not present in array."<<endl;
    }
    else{
        cout<<"Key: "<<key<<" is present at index: "<<flag<<endl;        
    }
    return 0;
}