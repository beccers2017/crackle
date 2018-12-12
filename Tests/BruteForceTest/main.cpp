#include <iostream>
#include <fstream>
#include "BruteForce.h"

int main() {
	std::cout << "Enter the user name of the password you are trying to crack" << std::endl;
	std::string userName;
	std::cin >> userName;
	
	BruteForce b(userName);
	//std::cout << "Would you like to write the combinations generated during the Bruteforce attack to a file?" << std::endl;

	std::string filename;
	filename = "file.txt";
	
	const std::string &passChars = "abcde";
	int passwordLength = 5;
	const std::string &current = "";
	
	b.loadWriteFile(filename);
	return 0;
	
	
}