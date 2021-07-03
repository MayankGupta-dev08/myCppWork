/*
Recursion is amazing and mind blowing topic itself. 
But ,

Cons of recursion:
1. Memory consumption is too much.
2. Overlapping of same problems
3. Some languages limit recursion by some count
4. Faulty recursion results in infinite loop
5. Most of all recursive way of problem solving has a good iterative way, also.

Pros :
Some problems are too hard to solve by regular iterative ways, in which recursion is must.

Ex. Tower of Hanoi, quick/merge sort, backtracking problems like sudoku solving

How to improve recursion:
1. Always make sure that there is correct terminating condition in function.
2. Use Tail-recursion whenever possible ( google tail-optimisation to understand )
3. Use memoization when you see overlapping problems. ( google memoization to understand )
*/

// To write a program ..for finding sum till n using recurrsion.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int sumTillN(int n){
    if(n==0)
        return 0;

    return (n + sumTillN(n-1));
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Sum till "<<n<<" is: "<<sumTillN(n)<<endl;
    return 0;
}