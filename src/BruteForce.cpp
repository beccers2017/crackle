/**
 * @file BruteForce.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

/**
 * Semantic versioning --most widely adopted version scheme, uses a sequence of three digits (Major.Minor.Patch)
 * an optional prerelease tag and optional build meta tag
 * 
 * Software using semantic versioning MUST declare a public API. This API can be declared in the code
 * itself or exist strictly in documentation.
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "BruteForce.h"
#include <boost/chrono.hpp>
#include <boost/timer.hpp>
#include <openssl/md5.h>
#include <openssl/sha.h>


using namespace boost::timer;

static const char passChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?@#$^&*";
static const int passCharSize = 70;
static const int maxPasswordSize = 8;

BruteForce::BruteForce() {
	//default constructor
}

BruteForce::BruteForce(std::string userName) {
	user = userName;
}

void BruteForce::launchBruteForceAttack() {
	//call validate hash?
}

/**
 * Validates that a valid hash has been inputted by the user
 * @param string hash
 * @return true or false
 */
//this check may want to be moved into the interface
/**
bool BruteForce::validateHashType(std::string &hashType) {
	if(hashType == "MD5" || hashType == "SHA1" || hashType == "SHA256" || hashType == "SHA512") {
		return true;
	}
	else {
		std::cout << "An invalid hash type has been entered. This program supports MD5, SHA1, SHA256 and SHA512 type hashes." << std::endl;
		return false;
	}
}
*/

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

/**
 * [BruteForce::calculateHash_MD5 description]
 * MD5() computes the message digest of the n bytes at d 
 * and place it in md(which must have a space for 
 * MD5_DIGEST_LENGTH == 16 bytes of output). If md is 
 * NULL, the digest is placed in a static array
 * This function returns a pointer to the hash value
 */
void BruteForce::calculateHash_MD5(std::string input) {
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
}

void BruteForce::calculateHash_SHA1(std::string input) {
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
}

void BruteForce::calculateHash_SHA256(std::string input) {
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
}

void BruteForce::calculateHash_SHA512(std::string input) {
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
}

/**
 * beginnings of functions used to measure time processes take 
 * NOTE: These are not in their intended location, these are just
 * here as I continue to develop the larger functions.
 */

//Getting timepoint before the function is called
using namespace std::chrono;
auto start = high_resolution_clock::now();

//getting timepoint after the function is called
using namespace std::chrono;
auto stop = high_resolution_clock::now();

//get the difference in timepoints and cast it to required units
auto duration = duration_cast<microseconds>(stop - start);
std::cout << duration.count() << std::endl;

/**
 * Sample brute force algorithm with recursion
 */

void visit(std::string const& chars, size_t max_len, std::string const& cur) {
	if(cur.length() == max_len) {
		return;
	}
	else {
		for(auto c : chars) {
			std::string next = cur + c;
			std::cout << next << std::endl;
			visit(chars, max_len, next);
		}
	}
}



