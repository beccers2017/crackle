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
		BruteForce(std::string userName);
		bool writeToFile(std::ofstream *filename);
		void launchBruteForceAttack(std::string const& chars, int passwordLength; std::string const& current);
		std::string calculateHash_MD5(std::string input);
		std::string calculateHash_SHA1(std::string input);
		std::string calculateHash_SHA256(std::string input);
		std::string calculateHash_SHA512(std::string input);
	private:
		std::string user;
};
#endif