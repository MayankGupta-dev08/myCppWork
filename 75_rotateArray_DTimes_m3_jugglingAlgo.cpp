/*Program for array rotation
    METHOD 3 (A Juggling Algorithm) 
        This is an extension of method 2. Instead of moving one by one, divide the array in different sets 
        where number of sets is equal to GCD of n and d and move the elements within sets. 
        If GCD is 1 as is for the above example array (n = 7 and d =2), then elements will be moved within one set only, we just start with temp = arr[0] and keep moving arr[I+d] to arr[I] and finally store temp at the right place.

        Here is an example for n =12 and d = 3. GCD is 3 and 
        Let arr[] be {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
        a) Elements are first moved in first set – (See below 
        diagram for this movement)
                arr[] after this step --> {4 2 3 7 5 6 10 8 9 1 11 12}

        b)    Then in second set.
                arr[] after this step --> {4 5 3 7 8 6 10 11 9 1 2 12}

        c)    Finally in third set.
                arr[] after this step --> {4 5 6 7 8 9 10 11 12 1 2 3}

    Time complexity : O(n) 
    Auxiliary Space : O(1)
*/

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    
    return gcd(b, a%b);
}

void rotateArray_dTimes(int arr[], int n, int d){
    d = d % n;  // To handle if d >= n
    int sets = gcd(n, d);
    for (int i = 0; i < sets; i++){
        int temp = arr[i];
        int j=i;
        while(1){
            int k=(j+d)%n;
            if(k==i)
                break;
            arr[j] = arr[k];
            j=k;
        }
        arr[j]=temp;
    }
}

void displayArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 3; 
    
    cout<<"Inital array:-\n";
    displayArray(arr, n);
    rotateArray_dTimes(arr, n, d);
    cout<<"After rotating array "<<d<<" times clockwise:-\n";
    displayArray(arr, n);

    return 0;
}

// Inital array:-
// 1 2 3 4 5 6 7 8 9 10 11 12
// After rotating array 3 times clockwise:-
// 4 5 6 7 8 9 10 11 12 1 2 3