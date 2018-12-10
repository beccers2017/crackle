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
const std::string lowerChars = "abcdefghijklmnopqrstuvwxyz";
const std::string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string numbers = "0123456789";
const std::string specialChars = "!?@#$^&*";
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
		auto duration = duration_cast<seconds>(stop - start);
		std::cout << "Time taken by the function: " << duration.count() << " seconds" << std::endl;
		file.close();
		return true;
	}
}

void BruteForce::launchBruteForceAttack(const std::string &passChars, int passwordLength, const std::string &current, std::ostream &file) {
	if(current.length() == passwordLength) {
		return;
	}
	else {
		for(auto c: passChars) {
			std::string next = current + c;
			file << next << std::endl;
			testPassword(user, next);
			//debugging line
			std::cout << next << std::endl;
			launchBruteForceAttack(passChars, passwordLength, next, file);
		}
	}
}

bool BruteForce::testPassword(std::string user, std::string password) {
	/* Concatenate multiple strings together to firm the long command string? */
	std::string 
	
	
	
	std::string result;
	std::string command = "curl -w \"HTTP Status:%{http_code}\" -d \"username=user3&password=password1&submit=Login\" http://localhost/Login-Test/login.php -v";
	result = std::system(command.c_str());
	std::cout << std::endl;
	std::cout << result << std::endl;
}



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





