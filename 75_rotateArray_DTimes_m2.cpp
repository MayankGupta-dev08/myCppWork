/*Program for array rotation
    Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
    arr[] = [3, 4, 5, 6, 7, 1, 2]

    METHOD 2 (Rotate one by one)  
        leftRotate(arr[], d, n)
        start
        For i = 0 to i < d
            Left rotate all elements of arr[] by one
        end

    Time complexity : O(n * d) 
    Auxiliary Space : O(1)
*/


#include <iostream>
using namespace std;

void rotateArrayFromLeftOnce(int arr[], int n){
    int temp = arr[0];
    for (int i = 0; i < n-1; i++)
        arr[i] = arr[i+1];
    
    arr[n-1] = temp;
}

void rotateArray_dTimes(int arr[], int n, int d){
    for (int i = 0; i < d; i++)
        rotateArrayFromLeftOnce(arr, n);
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