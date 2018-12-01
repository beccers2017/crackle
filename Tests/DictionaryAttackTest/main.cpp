#include <iostream>
#include <string>
#include "DictionaryAttack.h"

bool validateHashType(std::string &hashType) {
	if(hashType == "MD5" || hashType == "SHA1" || hashType == "SHA256" || hashType == "SHA512") {
		return true;
	}
	else {
		std::cout << "An invalid hash type has been entered. This program supports MD5, SHA1, SHA256 and SHA512 type hashes." << std::endl;
		return false;
	}
}

int main() {
	std::string filename;
	filename = "parsedWordlist.txt";
	
	std::string uHash;
	std::cout << "Enter a hash: " << std::endl;
	std::cin >> uHash;
	
	std::string hashType;
	std::cout << "Enter a hash type: " << std::endl;
	std::cin >> hashType;
	validateHashType(hashType);
	if(false) {
		std::cout << "Wrong hash type entered" << std::endl;
		return 0;
	}
	
	DictionaryAttack d(uHash);
	d.loadDictionary(filename);
	//d.launchDictionaryAttack(filename, hashType);
	
}