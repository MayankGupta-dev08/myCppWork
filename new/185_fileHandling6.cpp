/* File Handling with C++ using ifstream & ofstream class object*/
/* To write the Content in File*/
/* Then to read the content of file*/


#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout;      // Creation of ofstream class object
	string line;

	fout.open("sample.txt");
	// Execute a loop If file successfully opened
	while (fout) {

		// Read a Line from standard input
		getline(cin, line);

		// Press -1 to exit
		if (line == "-1")
			break;

		// Write line in file
		fout << line << endl;
	}
	fout.close();

	// Creation of ifstream class object to read the file
	ifstream fin;

	// by default open mode = ios::in mode
	fin.open("sample.txt");

	// Execute a loop until EOF (End of File)
	while (fin) {

		// Read a Line from File
		getline(fin, line);

		// Print line in Console
		cout << line << endl;
    }
	fin.close();

	return 0;
}


// Output
// hello my name is mayank
// this is c++ language
// coding is love
// -1
// hello my name is mayank
// this is c++ language
// coding is love
