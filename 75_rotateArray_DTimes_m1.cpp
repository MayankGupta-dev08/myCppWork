/*Program for array rotation
    Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
    arr[] = [3, 4, 5, 6, 7, 1, 2]

    METHOD 1 (Using temp array) 
        Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
        1) Store the first d elements in a temp array
        temp[] = [1, 2]
        2) Shift rest of the arr[]
        arr[] = [3, 4, 5, 6, 7, 6, 7]
        3) Store back the d elements
        arr[] = [3, 4, 5, 6, 7, 1, 2]

    Time complexity : O(n) 
    Auxiliary Space : O(d)  
*/


#include <iostream>
using namespace std;

void rotateArray_dTimes(int arr[], int n, int d){
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[i];
    
    for (int i = 0; i < n-d; i++)
        arr[i] = arr[i+d];
    
    for (int i=n-d, j=0; i<n; i++, j++)
        arr[i] = temp[j];
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2, n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Inital array:-\n";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    rotateArray_dTimes(arr, n, d);
    cout<<"After rotating array "<<d<<" times clockwise:-\n";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

// Inital array:-
// 1 2 3 4 5 6 7 
// After rotating array 2 times clockwise:-
// 3 4 5 6 7 1 2