/**
 * @file
 * @author Rebecca Donohoe
 * @version
 */

#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <iostream>

class BruteForce {
	public:
		BruteForce();
		BruteForce(std::string userName);
		bool validateHashType(std::string &hash);
		std::string BruteForceAttack(int maxAttempts);
		void calculateHash_MD5();
		void calculateHash_SHA1();
		void calculateHash_SHA256();
		void calculateHash_SHA512();
	private:
		std::string user;
};
#endif