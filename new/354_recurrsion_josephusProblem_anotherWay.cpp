/*~~~~~~~~~~~~~~~~~~Josephus Problem | Game of Death in a circle | Execution in Circle~~~~~~~~~~~~~~~~~~
    Given two integers, n and k, where n is the number of plyers in game and k is the killNumber.
    Rules of game:-
        1.  n players form a circle and their is only one gun which is used to kill one player at a time. 
        2.  game starts from a player (initially from 1) and player at position k is killed such that the player from who counting starts is also included in counting k.
        3.  next time the game again starts from the player just adjacent to killed one who is also alive and so on the game is played till only one player is left.
        4.  counting always follows an order ie, clockwise for whole game or counter-clockwise

    Example: 
        Total players in circle: 5
        Player to be killed at: 3 from starting.
        Last player standing at position: 4 from starting.
        ---------------------------------------------
        Total players in circle: 40
        Player to be killed at: 7 from starting.
        Last player standing at position: 24 from starting.
*/

#include <iostream>
#include <vector>
using namespace std;

int game_recurr(vector<int> &players, int k, int idx){
    if(players.size()==1)
        return players[0];
    
    idx = (idx+k)%players.size();
    players.erase(players.begin()+idx); //erases element at index idx   //vector is automatically reduced and elements have arranged themselves.
    game_recurr(players, k, idx);
}

void JhosephusGame(int n, int k){
    cout<<"Total players in circle: "<<n<<endl;
    cout<<"Player to be killed at: "<<k<<" from starting."<<endl;
    
    vector<int> players;
    for(int i=1; i<=n; i++)
        players.push_back(i);
    
    int ans = game_recurr(players, k-1, 0); //done k-1 to exclude starting element
    cout<<"Last player standing at position: "<<ans<<" from starting."<<endl;
}

int main(){
    int n=5, k=3;
    JhosephusGame(n,k);
    
    cout<<"------------------------------------------------\n";
    
    n=40, k=7;
    JhosephusGame(n,k);
    return 0;
}

// Total players in circle: 5
// Player to be killed at: 3 from starting.
// Last player standing at position: 4 from starting.
// ------------------------------------------------
// Total players in circle: 40
// Player to be killed at: 7 from starting.
// Last player standing at position: 24 from starting.