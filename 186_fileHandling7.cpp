/* File Handling with C++ using fstream class object */
/* To write the Content in File */
/* Then to read the content of file*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// Creation of fstream class object
	fstream fio;
	string line;

	// by default openmode = ios::in|ios::out mode
	// Automatically overwrites the content of file, To append
	// the content, open in ios:app
	// fio.open("sample.txt", ios::in|ios::out|ios::app)
	// ios::trunc mode delete all content before open
	fio.open("sample2.txt", ios::trunc | ios::out | ios::in);

	// Execute a loop If file successfully Opened
	while (fio) {

		// Read a Line from standard input
		getline(cin, line);

		// Press -1 to exit
		if (line == "-1")
			break;

		// Write line in file
		fio << line << endl;
	}

	// point read pointer at beginning of file
	fio.seekg(0, ios::beg);

	// Execute a loop untill EOF (End of File)
	while (fio) {

		// Read a Line from File
		getline(fio, line);

		// Print line in Console
		cout << line << endl;
	}
	fio.close();

	return 0;
}
