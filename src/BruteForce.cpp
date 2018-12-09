/**
 * @file BruteForce.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include "BruteForce.h"
#include <chrono>
#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std::chrono;

//static const char passChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?@#$^&*";
//const char* passChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?@#$^&*";
const std::string passChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?@#$^&*";
static const int passCharSize = 70;
static const int maxPasswordSize = 8;

BruteForce::BruteForce(std::string userName) {
	user = userName;
}

bool BruteForce::loadWriteFile(std::string &filename) {
	std::ofstream file;
	file.open(filename);
	if(!file.is_open()) {
		std::cout << "The output file was unable to be loaded successfully." << std:: endl;
		return false;
	}
	else {
		std::cout << "The output file was loaded successfully." << std::endl;
		
		auto start = high_resolution_clock::now();
		launchBruteForceAttack(passChars, passwordLength, current, file);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		std::cout << "Time taken by the function: " << duration.count() << " microseconds" << std::endl;
		/**
		file.close();
		*/
		return true;
	}
}

//could ask user to give a password length, instructing them that the length has to be <=8
//first parameter will probably need to be editted to match passChars
void BruteForce::launchBruteForceAttack(const std::string &passChars, int passwordLength; const std::string &current, std::ostream &file) {
	if(current.length() == passwordLength) {
		return;
	}
	else {
		for(auto c: passChars) {
			std::string next = current + c;
			file << next << std::endl;
			std::cout << next << std::endl;
			launchBruteForceAttack(passChars, passwordLength, next, file);
		}
	}
}



/**
string BruteForce::BruteForceAttack(int maxAttempts) { //parameter maybe being the max number of attempts? or a timeout
	auto_cpu_timer timer;
	
	int attempts = 0;

	for(int i = 0; i < 70; i++) {
		for(int j = 0; j < 70; j++) {
			for(int k = 0; k < 70; k++) {
				for(int n = 0; n < 70; n++) {
					for(int m = 0; n < 70; m++) {
						std::string possiblePassword = "";
						possiblePassword += passChars[i];
						possiblePassword += passChars[j];
						possiblePassword += passChars[k];
						possiblePassword += passChars[n];
						possiblePassword += passChars[m];
					}
				}
			}
		}
	}
	std::string encryptedPassword = calculateHash_MD5(possiblePassword);

	if(possiblePassword == password) {
		return possiblePassword;
	}
	else {
		attempts++;
		if(attempts == maxAttempts) {
			std::cout << "Maximum number of attempts reached for brute force." << std::endl;
		}
		else {
			//move onto generating the next password (maybe recursion?)
		}
	}
}
*/

std::string BruteForce::calculateHash_MD5(std::string input) {
	unsigned char digest[MD5_DIGEST_LENGTH];
	const char* std::string str = input.c_str();
	
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, str, strlen(str));
	MD5_Final(digest, &ctx);
	
	char mdString[MD5_DIGEST_LENGTH*2 + 1];
	for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	}
	printf("MD5 digest: %s\n", mdString);
	return mdString;
}

std::string BruteForce::calculateHash_SHA1(std::string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	const char* std::string str = input.c_str();
	
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, str, strlen(str));
	SHA1_Final(digest, &ctx);
	
	char mdString[SHA_DIGEST_LENGTH*2 + 1];
	for(int i = 0; i < SHA_DIGEST_LENGTH; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	}
	printf("SHA1 digest: %s\n", mdString);
	return mdString;
}

std::string BruteForce::calculateHash_SHA256(std::string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	const char* std::string str = input.c_str();
	
	SHA_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, str, strlen(str));
	SHA256_Final(digest, &ctx);
	
	char mdString[SHA_DIGEST_LENGTH*2 + 1];
	for(int i = 0; i < SHA_DIGEST_LENGTH; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	}
	printf("SHA256 digest: %s\n", mdString);
	return mdString;
}

std::string BruteForce::calculateHash_SHA512(std::string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	const char* std::string str = input.c_str();

	SHA_CTX ctx;
	SHA512_Init(&ctx);
	SHA512_Update(&ctx, str, strlen(str));
	SHA512_Final(digest, &ctx);
	
	char mdString[SHA_DIGEST_LENGTH*2 + 1];
	for(int i = 0; i < SHA_DIGEST_LENGTH; i++) {
		sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
	}
	printf("SHA512 digest: %s\n", mdString);
	return mdString;
}





