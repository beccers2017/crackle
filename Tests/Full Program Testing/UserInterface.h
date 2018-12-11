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
		bool validateHashType(std::string &hash_type);
	private:
};
#endif