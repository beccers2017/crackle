#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

void launchBruteForceAttack(const std::string &passChars, int passwordLength, const std::string &current, std::ostream &file);
bool loadWriteFile(std::string &filename);

int main() {
	std::string filename;
	filename = "file.txt";
	
	const std::string &passChars = "abcde";
	int passwordLength = 5;
	const std::string &current = "";
	
	loadWriteFile(filename);
	return 0;
}


void launchBruteForceAttack(const std::string &passChars, int passwordLength, const std::string &current, std::ostream &file) {
	//int count = 0;
	if(current.length() == passwordLength) {
		return;
	}
	else {
		for(auto c: passChars) {
			std::string next = current + c;
			file << next << std::endl;
			//count++;
			std::cout << next << std::endl;
			launchBruteForceAttack(passChars, passwordLength, next, file);
		}
		//std::cout << "The number of possible passwords created is: " << count << " passwords" << std::endl;
	}
}

bool loadWriteFile(std::string &filename) {
	const std::string &passChars = "abcde";
	int passwordLength = 5;
	const std::string &current = "";

	std::ofstream file;
	file.open(filename);
	if(!file.is_open()) {
		std::cout << "The output file was unable to be loaded successfully." << std:: endl;
		return false;
	}
	else {
		std::cout << "The output file was loaded successfully." << std::endl;
		
		auto start = std::chrono::high_resolution_clock::now();
		launchBruteForceAttack(passChars, passwordLength, current, file);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "Time taken by the function: " << duration.count() << " microseconds" << std::endl;
		
		file.close();

		return true;
	}
}

