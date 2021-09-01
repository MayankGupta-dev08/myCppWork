// To write a program ..to sort a string using recurrsion

#include <iostream>
#include <string>
using namespace std;

void insertChar(string &s, int temp){
    if(s.length()==0 || s[s.length()-1]<=temp){
        s.push_back(temp);
        return;
    }
    int val = s[s.length()-1];
    s.pop_back();
    insertChar(s, temp);
    s.push_back(val);
}

void sortString(string &s){
    if(s.length()==0)           //base condition
        return;
    
    int temp = s[s.length()-1]; //storing last element
    s.pop_back();               //removing it from string 
    sortString(s);              //now sending string of elements n-1
    insertChar(s, temp);        
    //inserting temp at right position using insert function which is also recurrsive
}

int main(){
    string s = "897456123";
    cout<<"String before sorting: "<<s<<endl;
    sortString(s);
    cout<<"String after sorting : "<<s<<endl;
    return 0;
}

// String before sorting: 897456123
// String after sorting : 123456789