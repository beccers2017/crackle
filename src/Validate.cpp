/**
 * @file Validate.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include "Validate.h"



Validate::Validate(std::string hash_type) {
	hashType = hash_type;
}

/* Might need to convert the hash type inside the user interface, because once its converted, it makes more sense to set the private variable at this point.
 * Maybe this entire class is useless and these functions would both be better served within the user interface and performed before any object declaration.
 */
std::string Validate::validateUppercaseString(std::string hashType) {
	std::transform(hashType.begin(), hashType.end(), hashType.begin(), ::toupper);
	validateHashType(hashType);
}

/* if this function is kept within user interface, might be able to loop it so that if a wrong hash type has been entered, the user can try again instead
 * of the program just quiting on them
 */
bool Validate::validateHashType(std::string &hashType) {
	if(hashType == "MD5" || hashType == "SHA1" || hashType == "SHA256" || hashType == "SHA512") {
		return true;
	}
	else {
		std::cout << "An invalid hash type has been entered. This program supports MD5, SHA1, SHA256 and SHA512 type hashes." << std::endl;
		return false;
	}
}
