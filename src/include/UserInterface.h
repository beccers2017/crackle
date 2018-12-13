/**
 * @file UserInterface.h
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
using namespace std;

class UserInterface {
	public:
		UserInterface();
		void printInfo();
		void printHelp();
		void selection();
		void menu();
		void validateUppercaseString(std::string hash_type);
		bool validateHashType(std::string &hash_type);
		bool validatePasswordSize(int password_length);
		void questions();
		void parse_cmd(int argc, char *argv[]);
	private:
};
#endif