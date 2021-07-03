// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Game of Death~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Rules of game:-
// 1.   n number of friends form a circle and their is one gun which is used in game,
        // first friend will be denoted by 0 and last by n-1
// 2.   suppose, game starts from a person than he will shoot the person who is next to next
        // ie. not the one who is immediate next but after him, it could be him also if he has the gun and only two are remaining than has to shoot himself
        // for this we will use, k=3, including him as first, he will shoot the third person 
// 3.   this will always follow an order ie, clockwise for whole game or counter-clockwise


// To write a program ..for solving josephus problem

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Jhosephus(int n, int k){
    if (n==1)
        return 0;   //if only 1 player so he will have index0 so he will be the winner

    return ((Jhosephus(n-1, k) + k) % n);
}

int main(){

    int n;
    cout<<"Enter total number of friend for this game: ";
    cin>>n;
    cout<<"Winner of the game is player with index: "<<Jhosephus(n,3)<<endl;
    cout<<"Player standing at position: "<<(Jhosephus(n,3) + 1)<<" from starting."<<endl;
    return 0;
}

// Output
// Enter total number of friend for this game: 5
// Winner of the game is player with index: 3
// Player standing at position: 4 from starting.