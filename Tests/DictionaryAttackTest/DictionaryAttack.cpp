/**
 * @file DictionaryAttack.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include "DictionaryAttack.h"
//#include <boost/chrono.hpp>
//#include <boost/timer.hpp>
#include <openssl/md5.h>
#include <openssl/sha.h>

//using namespace boost::timer;

/**
 * 
 * @param
 * @param
 * @return
 */

DictionaryAttack::DictionaryAttack(std::string givenHash, std::string hash_Type) {
	hash = givenHash;
	hashType = hash_Type;
}

/**
 * [DictionaryAttack::LoadDictionary description]
 * @param  filename [description]
 * @return          [description]
 */
bool DictionaryAttack::loadDictionary(std::string filename) {
	//int attempts = 0;
	std::string line;
	
	//debugging line
	//std::cout << "Inside loadDictionary Function" << std::endl;
	
	std::ifstream file(filename);
	file.open(filename);
	
	if(!file.is_open()) {
		std::cout << "The dictionary file was unabled to be loaded successfully." << std::endl;
		return false;
	}
	else {
		std::cout << "The dictionary file was loaded successfully" << std::endl;
		launchDictionaryAttack(&file,hashType);
		
	/**
	file.close();
	*/
	return true;
	}
}

/**
 * [DictionaryAttack::launchDictionaryAttack description]
 * @param filename     [description]
 * @param hashType [description]
 */
void DictionaryAttack::launchDictionaryAttack(std::ifstream *filename, std::string &hashType) {
	std::string line;
	int lineCount = 0;
	
	std::cout << "Launching Dictionary Attack" << std::endl;
	
	while(!filename->eof()) {
		*filename >> line;
		
		//debugging line
		std::cout << line << std::endl;
		lineCount++;
	
			std::string DictionaryHash;
			
			//debugging line
			//std::cout << "The hashType is: " << hashType << std::endl;
			
			if(hashType == "MD5") {
				//both calculateHash_MD5 and compareHashes need to be in a loop to keep running through the dictionary
				std::cout << line << std::endl;
				
				DictionaryHash = calculateHash_MD5(line);
				//debugging line
				std::cout << "The dictionaryHash is: " << DictionaryHash << std::endl;
				
				//need to save the return value of compareHashes in a variable to be able to use the if statement
				compareHashes(DictionaryHash, line);
				if(true)
					//return 0;
					exit(0);
			}
			else if(hashType == "SHA1") {
				DictionaryHash = calculateHash_SHA1(line);
				compareHashes(DictionaryHash, line);
				if(true)
					//return 0;
					exit(0);
			}
			else if(hashType == "SHA256") {
				DictionaryHash = calculateHash_SHA256(line);
				compareHashes(DictionaryHash, line);
				if(true)
					//return 0;
					exit(0);
			}
			else if(hashType == "SHA512") {
				DictionaryHash = calculateHash_SHA512(line);
				compareHashes(DictionaryHash, line);
				if(true)
					//return 0;
					exit(0);
			}
			else {
				std::cout << "Error: No hash type specified" << std::endl;
				break;
			}
	}
}

std::string DictionaryAttack::calculateHash_MD5(std::string input) {
	unsigned char digest[MD5_DIGEST_LENGTH];
	//const char* std::string str = input.c_str();
	const char* str = input.c_str();
	
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, str, strlen(str));
	MD5_Final(digest, &ctx);
	
	char mdString[MD5_DIGEST_LENGTH*2 + 1];
	for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	}
	//printf("MD5 digest: %s\n", mdString);
	return mdString;
}

std::string DictionaryAttack::calculateHash_SHA1(std::string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	//const char* std::string str = input.c_str();
	const char* str = input.c_str();
	
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, str, strlen(str));
	SHA1_Final(digest, &ctx);
	
	char mdString[SHA_DIGEST_LENGTH*2 + 1];
	for(int i = 0; i < SHA_DIGEST_LENGTH; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	}
	//printf("SHA1 digest: %s\n", mdString);
	return mdString;
}

std::string DictionaryAttack::calculateHash_SHA256(std::string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	//const char* std::string str = input.c_str();
	const char* str = input.c_str();
	
	SHA256_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, str, strlen(str));
	SHA256_Final(digest, &ctx);
	
	char mdString[SHA_DIGEST_LENGTH*2 + 1];
	for(int i = 0; i < SHA_DIGEST_LENGTH; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	}
	//printf("SHA256 digest: %s\n", mdString);
	return mdString;
}

std::string DictionaryAttack::calculateHash_SHA512(std::string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	//const char* std::string str = input.c_str();
	const char* str = input.c_str();

	SHA512_CTX ctx;
	SHA512_Init(&ctx);
	SHA512_Update(&ctx, str, strlen(str));
	SHA512_Final(digest, &ctx);
	
	char mdString[SHA_DIGEST_LENGTH*2 + 1];
	for(int i = 0; i < SHA_DIGEST_LENGTH; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	}
	//printf("SHA512 digest: %s\n", mdString);
	return mdString;
}

/**
 * [DictionaryAttack::compareHashes description]
 * @param std::DictionaryHash [description]
 * @param line
 */
bool DictionaryAttack::compareHashes(std::string DictionaryHash, std::string line) {
	if(DictionaryHash == hash) {
		std::cout << "This program has found a match for the given hash." << std::endl;
		std::cout << "The matching password is: " << line << std::endl;
		//std::cout << "This program read through " << lineCount << "lines" << std::endl;
		return true;
	}
	else {
		return false;
	}
}
