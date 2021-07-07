// To write a program ..Given n items, each item has a certain value and weight. We have to maximize the value of the objects we can accommodate in a bag of weight W.

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// for returning the maximum value that can be held by knapsack
int knapsack(int wt[], int value[], int n, int W){
    if (n==0 || W==0)       //no more items left or bag is full
        return 0;
    
    if (wt[n-1]>W)          //wt of that last item is more than current capacity so check prev one.
        return knapsack(wt, value, n-1, W);

    return max( (knapsack(wt, value, n-1, W-wt[n-1]) + value[n-1]), knapsack(wt, value, n-1, W) );
        // max ((choice1: taking nth item, since index from 0 in array so taken as n-1 i.e. last item ),(choice2: not taking (n-1)th item ie. last item))  
}

int main(){

    int n =3, wt[] = {10,20,30}, value[] = {100,50,150}, W=50;
    // n - total number of items
    // wt - array for weight of individual items
    // value - array for value of individual items
    // W - total weight that knapsack can hold
    cout<<"Max value of items that can be collected: "<<knapsack(wt, value, n, W)<<endl;
    
    return 0;
}