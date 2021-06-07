/* JUMPS IN LOOPS OR FLOW CONTROL IN LOPPS
1.  break;      terminate the loop
2. continue;    skip to next iteration of loop
*/

#include<iostream>
using namespace std;

int main(){
    int countd = 1;
    int pktmoney = 3000;
    for (int i =1; i<=30; i++){

        if (i%2==0){
            continue;
        }
        if (pktmoney==0){
            break;
        }
        cout<<"Current pocket money: "<<pktmoney<<endl;
        cout<<"You can go outside\n\n";
        pktmoney -= 300;
        countd = i;
    }
    cout<<"pocket money left after: "<<countd<<" day is: "<<pktmoney<<endl;
    return 0;
}