// To write a program ..to bring certain number of discs (n) from a souce pole (A) to destination pole (C) using a helper pole (B). All disc are having a size which are intially arranged in increasing order in source with smallest on top.
    // Constraints:
        // only one disc can me moved at a time
        // no bigger disc can be on top of smaller disc.


#include <iostream>
using namespace std;

void printStepsSolving_towerOfHanoi(int n, char source, char helper, char destn){
    if (n==0)
        return;
    
    printStepsSolving_towerOfHanoi(n-1, source, destn, helper);    //sending n-1 from source to helper using destn
    cout<<"Moving a disc from "<<source<<" to "<<destn<<endl;
    printStepsSolving_towerOfHanoi(n-1, helper, source, destn);    //sending n-1 from helper to destn using source
}

int main(){

    int n;
    cout<<"Enter the number of discs in souce rod: ";
    cin>>n;
    printStepsSolving_towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

/*
-------------------OUTPUT-------------------
Enter the number of discs in souce rod: 3
Moving a disc from A to C
Moving a disc from A to B
Moving a disc from C to B
Moving a disc from A to C
Moving a disc from B to A
Moving a disc from B to C
Moving a disc from A to C
*/