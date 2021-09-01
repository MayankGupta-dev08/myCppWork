// ~~~~~~~~~~~~~~~~~~Josephus Problem | Game of Death in a circle | Execution in Circle~~~~~~~~~~~~~~~~~~
    // Rules of game:-
        // 1.   n number of friends form a circle and their is one gun which is used in game, first friend will be denoted by 0 and last by n-1
        // 2.   suppose, game starts from a person than he will shoot the person who is next to next ie. not the one who is immediate next but after him, it could be him also if he has the gun and only two are remaining than has to shoot himself for this we will use, k=3, including him as first, he will shoot the third person 
        // 3.   this will always follow an order ie, clockwise for whole game or counter-clockwise


#include <iostream>
using namespace std;

int Jhosephus(int n, int k){
    if (n==1)
        return 0;   //if only 1 player so he will have index0 so he will be the winner

    return ((Jhosephus(n-1, k) + k) % n);
}

int main(){
    int n=5, k=3;
    cout<<"Total players in circle: "<<n<<endl;
    cout<<"Player to be killed at: "<<k<<" from starting."<<endl;
    cout<<"Last player standing at position: "<<(Jhosephus(n,k) + 1)<<" from starting."<<endl;
    
    cout<<"---------------------------------------------\n";
    
    n=40, k=7;
    cout<<"Total players in circle: "<<n<<endl;
    cout<<"Player to be killed at: "<<k<<" from starting."<<endl;
    cout<<"Last player standing at position: "<<(Jhosephus(n,k) + 1)<<" from starting."<<endl;
    return 0;
}

// Total players in circle: 5
// Player to be killed at: 3 from starting.
// Last player standing at position: 4 from starting.
// ---------------------------------------------
// Total players in circle: 40
// Player to be killed at: 7 from starting.
// Last player standing at position: 24 from starting.