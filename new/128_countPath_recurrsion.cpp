// To write a program ..count thr number of paths possible from starting point to e point in a gameboard when playing with a dice using recurrsion 

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// s->start and e->end
int countPaths(int s, int e){
    if (s==e){
        return 1;
    }
    if (s>e){
        return 0;
    }
    int count =0;
    for (int i = 1; i <= 6; i++){    //for choice with dice
        count += countPaths(s+i,e);
    }
    return count;
}

int main(){

    int s,e;
    cout<<"Enter value of s pt and e pt: ";
    cin>>s>>e;
    cout<<"Number of paths: "<<countPaths(s,e)<<endl;
    
    return 0;
}

/*OUTPUTS
Enter value of s pt and e pt: 0 3
Number of paths: 4
Enter value of s pt and e pt: 0 4
Number of paths: 8
Enter value of s pt and e pt: 1 5
Number of paths: 8
*/