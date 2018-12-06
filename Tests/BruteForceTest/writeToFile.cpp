#include <iostream>
#include <string>
#include <fstream>

bool writeToFile(std::string filename) {
	std::ofstream file;
	file.open(filename);
	
	if(!file.is_open()) {
		std::cout << "The output file was unable to be loaded successfully." << std:: endl;
		return false;
	}
	else {
		std::cout << "The file was loaded successfully" << std::endl;
		file << "Writing to a file test.\n";
		file.close();
		return true;
	}
}

int main() {
	std::string filename = "write.txt";
	writeToFile(filename);
	return 0;
}