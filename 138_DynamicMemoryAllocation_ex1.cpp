// DYNAMIC MEMORY ALLOCATION

#include <iostream>
// #include <new>          //header file for using (nothrow) exception
using namespace std;

// if (nothrow) is not used and allocation fails, ie. user enters a number too large for the computer to handle, an exception is thrown
// if (nothrow) is used and allocation fails, the failure can be detected by checking if pointer is a null pointer:

int main ()
{
    int a;
    cin>>a;
    int* q = new int(a);    //one way
    float *r = new float;   //other way
    *r = 84.98;
    cout<<"Pointer q with dynamic memory allocated: "<<*q<<endl;
    cout<<"Pointer r with dynamic memory allocated: "<<*r<<endl;
    delete(q);
    delete(r);


    int n;
    int* p;
    cout << "How many numbers would you like to type? ";
    cin >> n;
    p = new int[n];     //For 1D array
    
    //Since this memory allocation of 1D array is dependent on the user input n which is size, this is the use. 
    
    // But for 1D array its not that useful as function doesn't need size, void func(int arr[]) is also correct.
    // This is more useful in 2D array.
    
    for (int i=0; i<n; i++){
        cout << "Enter number: ";
        cin >> p[i];
    }

    cout << "You have entered: ";
    for (int i=0; i<n; i++)
        cout << p[i] << ", ";

    delete[] p;     //for array
    return 0;
}