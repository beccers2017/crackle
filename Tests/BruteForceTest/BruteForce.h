/**
 * @file
 * @author Rebecca Donohoe
 * @version
 */

#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <iostream>
#include <fstream>
#include <string>

class BruteForce {
	public:
		BruteForce(std::string userName);
		bool loadWriteFile(std::string &filename);
		void launchBruteForceAttack(const std::string &passChars, int passwordLength, const std::string &current, std::ostream &file);
		void launchBruteForceAttack(const std::string &passChars, int passwordLength, const std::string &current);
		void testPassword(std::string user, std::string password);
		bool validateTest();
	private:
		std::string user;
		
};
#endif