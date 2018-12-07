#include <iostream>
#include <string>
#include "DictionaryAttack.h"

//add a instruction to enter hash type as all capital letters or add a check that will take it as lower case letters, and maybe convert to all upper case letters

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
	//filename = "parsedWordlist.txt";
	filename = "smallWordlist.txt";
	
	std::string uHash;
	std::cout << "Enter a hash: " << std::endl;
	std::cin >> uHash;
	
	std::string hash_type;
	std::cout << "Enter a hash type: " << std::endl;
	std::cin >> hash_type;
	validateHashType(hash_type);
	if(false) {
		std::cout << "Wrong hash type entered" << std::endl;
		return 0;
	}
	
	DictionaryAttack d(uHash, hash_type);
	d.loadDictionary(filename);
	//d.launchDictionaryAttack(filename, hashType);
	
}