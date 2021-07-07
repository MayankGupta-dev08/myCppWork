#include<iostream>
#include<fstream>   //header file which contains 3 classes -> fstream, ifstream, ofstream
#include<string>
using namespace std;

int main(){

    fstream myFile;     //object of fstream class
    
    myFile.open("file2.txt", ios:: out);            //write
    if(myFile.is_open()){
        myFile<<"--------This is File2--------\n"
          <<"first line in file2\n"
          <<"second line in file2\n"
          <<"third line in file2\nfourth line in file2\n"
          <<"for the time, this is it.\n\n";
        myFile.close();
    }
    
    myFile.open("file2.txt", ios:: app);            //append
    if(myFile.is_open()){
        myFile<<"--------Appending--------\n"
          <<"continuing from where we left\n"
          <<"we are finished updating!!!!\n";
        myFile.close();
    }

    myFile.open("file2.txt", ios:: in);            //read
    if(myFile.is_open()){
        string line;
        while(getline(myFile, line)){
            cout<<line<<endl;
        }
        myFile.close();
    }

    return 0;
}

// ------------OUTPUT------------
// --------This is File2--------
// first line in file2
// second line in file2
// third line in file2
// fourth line in file2
// for the time, this is it.

// --------Appending--------
// continuing from where we left
// we are finished updating!!!!