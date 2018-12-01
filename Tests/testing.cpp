#include <iostream>
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/md5.h>

using namespace std;

/**
 * MD5 and SHA1 hashes are working as expected. SHA256 and SHA512 are hashing without salts
 * which probably will decrese the effectiveness of this program at cracking those specific
 * hashes if don't account for this. Will likely need to add salts to both of these functions
 */

string calculateHash_MD5(string input) {
	unsigned char digest[MD5_DIGEST_LENGTH];
	const char* str = input.c_str();
	printf("The given input was: %s\n", input);
	
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


string calculateHash_SHA1(string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	const char* str = input.c_str();
	printf("The given input was: %s\n", str);
	
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

string calculateHash_SHA256(string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	const char* str = input.c_str();
	printf("The given input was: %s\n", str);
	
	SHA256_CTX ctx;
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

string calculateHash_SHA512(string input) {
	unsigned char digest[SHA_DIGEST_LENGTH];
	const char* str = input.c_str();
	printf("The given input was: %s\n", str);
	
	SHA512_CTX ctx;
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

int main() {
	string input = "";
	cout << "Enter a string to be hashed" << endl;
	cin >> input;
	
	calculateHash_MD5(input);
	calculateHash_SHA1(input);
	calculateHash_SHA256(input);
	calculateHash_SHA512(input);
	return 0;
}