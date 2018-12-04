#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int fileLoadRead(string filename) {
	string line;
	int count = 0;
	ifstream myFile;
	myFile.open(filename);

	if(myFile.is_open()) {
		while(!myFile.eof()) {
			myFile >> line;
			//testing line
			cout << line << endl;
			count++;
		}
		myFile.close();
		cout << "The line count is: " << count << endl;
		return count;
	}
	else {
		cout << "The dictionary failed to load" << endl;
		return -1;
	}
	
}

int main() {
	//string filename = "parsedWordlist.txt";
	string filename = "smallWordlist.txt";
	fileLoadRead(filename);
}