#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){

    fstream myFile;
    string line = "";
    cout<<"****Start writing in your secret Diary****\n";
    cout<<"****Tip: For stop writing, enter- exit****\n\n";

    // for taking input from the user in terms of lines and encoding that input in ASCII code format into a file
    myFile.open("secretDiary.txt", ios::out);
    while(line!="exit"){
        cout<<"Enter: ";
        getline(cin, line);
        if(line!="exit"){
            for(int i=0; i<line.length(); i++){
                myFile<<int(line[i])<<" ";
            }
            myFile<<endl;
        }
    }
    myFile.close();

    
    // for printing the encoded content of the file
    cout<<"\n---Encoded Content in file---\n";
    myFile.open("secretDiary.txt", ios::in);
    string lne1;
    while(getline(myFile, lne1)){
        cout<<lne1<<endl;
    }
    myFile.close();
    
    
    // for showing onto the screen
    cout<<"\n---Decoded Content from file---\n";
    myFile.open("secretDiary.txt", ios::in);
    string lne;
    while(getline(myFile, lne)){
        string apha = "";
        for (int i = 0; i < lne.length(); i++){
            if(lne[i]==' '){
                cout<<char(stoi(apha));
                apha = "";
                continue;
            }
            else{
                apha.push_back(lne[i]);
            }
        }
        cout<<endl; 
    }
    myFile.close();

    return 0;
}

// ------------OUTPUT------------
// ****Start writing in your secret Diary****
// ****Tip: For stop writing, enter- exit****

// Enter: Hello guys  
// Enter: I am Mayank
// Enter: I love Coding
// Enter: I have learnt C++ and python 
// Enter: exit

// ---Encoded Content in file---
// 72 101 108 108 111 32 103 117 121 115 
// 73 32 97 109 32 77 97 121 97 110 107 
// 73 32 108 111 118 101 32 67 111 100 105 110 103 
// 73 32 104 97 118 101 32 108 101 97 114 110 116 32 67 43 43 32 97 110 100 32 112 121 116 104 111 110 

// ---Decoded Content from file---
// Hello guys
// I am Mayank
// I love Coding
// I have learnt C++ and python