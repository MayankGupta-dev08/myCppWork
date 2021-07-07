// File Handling through C++ Classes
// To write a program ..to do file handling using open() method
// ----------------------Using Method2----------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    ofstream f1;
    cout<<"We are opening and writing in poem.txt"<<endl;
    f1.open("poem.txt", ios::out);
    // writing in the file
    f1<<"Twinkle, twinkle, little star,\n";
    f1<<"How I wonder what you are!\n";
    f1<<"Up above the world so high,\n";
    f1<<"Like a diamond in the sky.\n\n";
    f1<<"When the blazing sun is gone,\n";
    f1<<"When he nothing shines upon,\n";
    f1<<"Then you show your little light,\n";
    f1<<"Twinkle, twinkle, all the night.\n\n";
    f1<<"Then the traveler in the dark\n";
    f1<<"Thanks you for your tiny spark,\n";
    f1<<"How could he see where to go,\n";
    f1<<"If you did not twinkle so?\n\n";
    f1<<"In the dark blue sky you keep,\n";
    f1<<"Often through my curtains peep\n";
    f1<<"For you never shut your eye,\n";
    f1<<"Till the sun is in the sky.\n\n";
    f1<<"As your bright and tiny spark\n";
    f1<<"Lights the traveler in the dark,\n";
    f1<<"Though I know not what you are,\n";
    f1<<"Twinkle, twinkle, little star.";

    f1.close();
    cout<<"We have written in the file!"<<endl;
    cout<<"--------------------------------\n";
    
    ifstream f2;
    string data;
    f2.open("poem.txt", ios::in);
    while(f2.eof()==0){ //run till we have reached end of file, at end of file it will return 1
        getline(f2, data);  //returning one line at a time 
        cout<<data<<endl;   //printing that line on the screen, endl is necessarry it will not consider the newline charater of the file to print 
    }

    f2.close();
    return 0;
}

// --------------------------------Output--------------------------------
// We are opening and writing in poem.txt
// We have written in the file!
// --------------------------------      
// Twinkle, twinkle, little star,        
// How I wonder what you are!
// Up above the world so high,
// Like a diamond in the sky.

// When the blazing sun is gone,
// When he nothing shines upon,
// Then you show your little light,      
// Twinkle, twinkle, all the night.      

// Then the traveler in the dark
// Thanks you for your tiny spark,       
// How could he see where to go,
// If you did not twinkle so?

// In the dark blue sky you keep,        
// Often through my curtains peep        
// For you never shut your eye,
// Till the sun is in the sky.

// As your bright and tiny spark
// Lights the traveler in the dark,      
// Though I know not what you are,       
// Twinkle, twinkle, little star.