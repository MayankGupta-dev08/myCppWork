/*LIST OF STRING FUNCTIONS
1. str.append(str2)
2. str.clear()
3. str.empty()
4. str.compare(str2)
5. str.erase(start_pos, number_chars)
6. str.insert(at_pos, "substring") //rest will shift behind it
7. str.find() //retuens starting position of substring if found
8. str.length()
9. str.size()
10. str.substr()
11. str.stoi()

12. sort(s0.begin(), s0.end())                              //  #include<algorithm> 
12. sort(s_num.begin(), s_num.end(), greater<int>())        //  #include<algorithm>
13. transform(s1.begin(), s1.end(), s1.begin(), ::toupper)  //  #include<algorithm>
14. transform(s2.begin(), s2.end(), s2.begin(), ::tolower)  //  #include<algorithm>
15. reverse(s2.begin(), s2.end())                           //  #include<algorithm>

16. str.popback()   //Remove the last character. The string must be non-empty.
17. str.push_back(ch)   //char ch;  // Append a single character.

17. to_string(num)  // int to string
18. stoi(str)  /// string to int
*/


//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

// Adding strings using different ways
    string s1 = "Family: ", s2 = "Father-Mother, I love you";
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s1+s2<<endl;
    cout<<s1<<endl;

    string s3 = s1+s2;
    cout<<s3<<endl;

    string s4;
    s4.append(s1+s2);
    cout<<s4<<endl;

    s1.append(s2);
    cout<<s1<<endl;

// clearing content of a string and checking whether it is an empty string or not
    s4.clear();
    if (s4.empty()){
        cout<<"String is empty!!"<<endl;
    }

// comparing two strings
    string st1 = "abc", st2 = "xyz", st3 = "abc";
    if(st1.compare(st2)==0)
        cout<<"Both are same"<<endl;
    else
        cout<<"Both are different "<<st1.compare(st2)<<endl;

    if(st1.compare(st3)==0)
        cout<<"Both are same"<<endl;
    else
        cout<<"Both are different"<<st1.compare(st2)<<endl;


// Removing/erasing a some part of the string
    string st4 ="he is a nincompoop!!";
    st4.erase(0,8);
    cout<<st4<<endl;


// inserting a substring into a string
    st4 ="nincompoop!!";
    st4.insert(6, "lol");
    cout<<st4<<endl;

// Finding a substring in a string
    string st5 = "supercallifragilisticaspialydosiously";
    cout<<st5.find("call")<<endl;
    // cout<<st5.find("lol")<<endl; //returns some big number if not found
  

// finding length of the string
    cout<<st5.length()<<endl;
    cout<<st5.size()<<endl;

// creating a substring from the existing string
    string st = "nincompoop";
    string sb = st.substr(6, 4);
    cout<<sb<<endl;


// string to int
    string num = "133";
    int n = stoi(num);
    cout<<"num + 2: "<<n+2<<endl;
    cout<<"num + 5: "<<stoi(num)+5<<endl;


// int to string
    int num1 = 133;
    string n1 = to_string(num1)+"2";
    cout<<"num1 + 2: "<<n1<<endl;


// sorting using #include<algorithm> ans sort(strName.begin(), strName.end())
    string s0 = "sdjabfadalkdlasjlqwwmknda";
    cout<<s0<<endl;
    sort(s0.begin(), s0.end());
    cout<<s0<<endl;


// Remove the last character. The string must be non-empty.
    string st0 = "abc";
    st0.pop_back();
    cout<<st0<<endl;

// Append a single character.
    char ch = 'd';
    string str0 = "abc";
    str0.push_back(ch);
    cout<<str0<<endl;

    return 0;
}