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
#include <chrono>
#include <stdio.h>
#include "DictionaryAttack.h"
#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std::chrono;

/**
 * DictionaryAttack Constructor
 * @param givenHash
 * @param hash_type
 * @return 
 */

DictionaryAttack::DictionaryAttack(std::string givenHash, std::string hash_type) {
	hash = givenHash;
	hashType = hash_type;
}

/**
 * [DictionaryAttack::LoadDictionary description]
 * @param  filename [description]
 * @return          [description]
 */
bool DictionaryAttack::loadDictionary(std::string &filename) {
	std::string line;
	
	//debugging line
	//std::cout << "Inside loadDictionary Function" << std::endl;
	
	std::ifstream file;
	file.open(filename);

	if(!file.is_open()) {
		std::cout << "The dictionary file was unabled to be loaded successfully." << std::endl;
		return false;
	}
	else {
		std::cout << "The dictionary file was loaded successfully" << std::endl;
		launchDictionaryAttack(file);
		file.close();
		return true;
	}
}

/**
 * [DictionaryAttack::launchDictionaryAttack description]
 * @param filename     [description]
 * @param hashType [description]
 */
void DictionaryAttack::launchDictionaryAttack(std::ifstream &file) {
	std::string line;
	int lineCount = 0;
	std::string dictionaryHash;
	bool result;

	std::cout << "Launching Dictionary Attack" << std::endl;
	
	auto start = high_resolution_clock::now();
	
		if(hashType == "MD5") {
			//debugging line
			//std::cout << "Inside the MD5 if statement" << std::endl;
			while(!file.eof()) {
				file >> line;
				//std::cin.ignore();
				//std::getline(file, line, '\n');
				
				//debugging line
				std::cout << line << std::endl;
				lineCount++;
				
				dictionaryHash = calculateHash_MD5(line);
				std::cout << std::endl;
				
				//debugging line
				//std::cout << "The dictionary hash is: " << dictionaryHash << std::endl;
				//std::cout << std::endl;
				
				result = compareHashes(dictionaryHash, line);
				if(result == true) {
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					std::cout << std::endl;
					std::cout << "The time taken by this program to find a match was: " << duration.count() << " microseconds" << std::endl;
					std::cout << std::endl;
					std::cout << "This program read through " << lineCount << " lines to find a match." << std::endl;
					exit(0);
				}
			}
		}
		else if(hashType == "SHA1") {
			//debugging line
			//std::cout << "Inside the SHA1 if statement" << std::endl;
			while(!file.eof()) {
				std::cin.ignore();
				std::getline(file, line, '\n');
				
				//debugging line
				std::cout << line << std::endl;
				lineCount++;
				
				dictionaryHash = calculateHash_SHA1(line);
				std::cout << std::endl;
				
				//debugging line
				//std::cout << "The dictionary hash is: " << dictionaryHash << std::endl;
				//std::cout << std::endl;
				
				result = compareHashes(dictionaryHash, line);
				if(result == true) {
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					std::cout << std::endl;
					std::cout << "The time taken by this program to find the password that matched the hash was: " << duration.count() << " microseconds" << std::endl;
					std::cout << std::endl;
					std::cout << "This program read through " << lineCount << " lines" << std::endl;
					exit(0);
				}
			}
		}
		else if(hashType == "SHA256") {
			//debugging line
			//std::cout << "Inside the SHA256 if statement" << std::endl;
			while(!file.eof()) {
				std::cin.ignore();
				std::getline(file, line, '\n');
				
				//debugging line
				std::cout << line << std::endl;
				lineCount++;
				
				dictionaryHash = calculateHash_SHA256(line);
				std::cout << std::endl;
				
				//debugging line
				//std::cout << "The dictionary hash is: " << dictionaryHash << std::endl;
				//std::cout << std::endl;
				
				result = compareHashes(dictionaryHash, line);
				if(result == true) {
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					std::cout << std::endl;
					std::cout << "The time taken by this program to find the password that matched the hash was: " << duration.count() << " microseconds" << std::endl;
					std::cout << std::endl;
					std::cout << "This program read through " << lineCount << " lines" << std::endl;
					exit(0);
				}
			}
		}
		else if(hashType == "SHA512") {
			//debugging line
			//std::cout << "Inside the SHA512 if statement" << std::endl;
			while(!file.eof()) {
				std::cin.ignore();
				std::getline(file, line, '\n');
				
				//debugging line
				std::cout << line << std::endl;
				lineCount++;
				
				dictionaryHash = calculateHash_SHA512(line);
				std::cout << std::endl;
				
				//debugging line
				//std::cout << "The dictionary hash is: " << dictionaryHash << std::endl;
				//std::cout << std::endl;
				
				result = compareHashes(dictionaryHash, line);
				if(result == true) {
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					std::cout << std::endl;
					std::cout << "The time taken by this program to find the password that matched the hash was: " << duration.count() << " microseconds" << std::endl;
					std::cout << std::endl;
					std::cout << "This program read through " << lineCount << " lines" << std::endl;
					exit(0);
				}
			}
		}
		else {
			std::cout << "Error: Hash type did not match any supported hashes." << std::endl;
			exit(0);
		}
}
/**
 * [DictionaryAttack::calculateHash_MD5 description]
 * @param  input [description]
 * @return       [description]
 */
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
	//debugging line
	// std::cout << mdString << std::endl;
	return mdString;
}
/**
 * [DictionaryAttack::calculateHash_SHA1 description]
 * @param  input [description]
 * @return       [description]
 */
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
/**
 * [DictionaryAttack::calculateHash_SHA256 description]
 * @param  input [description]
 * @return       [description]
 */
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
/**
 * [DictionaryAttack::calculateHash_SHA512 description]
 * @param  input [description]
 * @return       [description]
 */
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
bool DictionaryAttack::compareHashes(std::string dictionaryHash, std::string line) {
	if(dictionaryHash == hash) {
		//debugging line
		//std::cout << "Inside the compare Hashes Function" << std::endl;
		std::cout << "This program has found a match for the given hash." << std::endl;
		std::cout << std::endl;
		std::cout << "The password that matches the given hash is: " << line << std::endl;
		return true;
	}
	else {
		return false;
	}
}
