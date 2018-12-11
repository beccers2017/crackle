/**
 * @file UserInterface.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include "UserInterface.h"

#include "termcolor/termcolor.hpp"
//#include "BruteForce.h"
#include "DictionaryAttack.h"
//#include <boost/program_options.hpp>

//using namespace boost::program_options;

UserInterface::UserInterface() {
	//default constructor
}

void UserInterface::printInfo() {
	
	//std::cout << "Filename: " << __FILE__ << std::endl;
	std::cout << std::endl;
	std::cout << termcolor::bold << termcolor::yellow << "  Date: " << __DATE__ << std::endl;
	std::cout << termcolor::bold << termcolor::yellow << "  Time: " << __TIME__ << std::endl;
	std::cout << std::endl;
	std::cout << "     " << termcolor::blue << "***********************************************************************************" << std::endl;
	std::cout << "     " << termcolor::blue << "*                          Crackle: A Password Cracker                            *" << std::endl;
	std::cout << "     " << termcolor::blue << "*                                 Version 0.1.0                                   *" << std::endl;
	std::cout << "     " << termcolor::blue << "*                           Written by Rebecca Donohoe                            *" << std::endl;
	std::cout << "     " << termcolor::blue << "***********************************************************************************" << std::endl;
	std::cout << termcolor::reset << std::endl;
	std::cout << std::endl;
	std::cout << "             " << termcolor::bold << termcolor::yellow << "This is a password cracking tool, intended for educational purposes." << termcolor::reset << std::endl;
	std::cout << "                     " << "This tool supports MD5, SHA1, SHA256, and SHA 512 hashes." << std::endl;
	std::cout << "          " << "Passwords can be cracked using a brute-force attack or a dictionary attack." << std::endl;
	std::cout << std::endl;
}

void UserInterface::selection() {
	std::cout << "Please select an option: " << std::endl;
	std::cout << "   [1] Brute-Force Attack" << std::endl;
	std::cout << "   [2] Dictionary Attack" << std::endl;
	std::cout << "   [3] Print Usage" << std::endl;
	std::cout << "   [4] Print Help Menu" << std::endl;
	std::cout << "   [5] Quit Program" << std::endl;
	menu();
}

/**
void UserInterface::printUsage() {
	std::cout << " Examples usage: " << std::endl;
	std::cout << "    ./crackle -d" << std::endl;
	std::cout << "   Using a custom dictionary file" << std::endl;
	std::cout << "    ./crackle -c /usr/csci3010-personal-project/Wordlists/parsedWordlist.txt" << std::endl;
	std::cout << std::endl;
}
*/
void UserInterface::printHelp() { 
	std::cout << std::endl;
	std::cout << " Usage: crackle [options] " << std::endl;
	std::cout << std::endl;
	std::cout << "    Options:" <<std::endl;
	std::cout << "        -d : use default dictionary file" << std::endl;
	std::cout << "        -c : use custom dictionary file" << std::endl; //need to add more usage information here on loading custom file
	std::cout << "        -h : Hash Type if known (required for dictionary attack)" << std::endl;
	std::cout << "        -o : write results to output file" << std::endl; //again add more usage information
	//std::cout << "        -l : Include a log file" << std::endl;
	std::cout << std::endl;
	std::cout << "    Examples: " << std::endl;
	std::cout << "        ./crackle -d" << std::endl;
	std::cout << "        ./crackle -c /usr/csci3010-personal-project/Wordlists/parsedWordlist.txt" << std::endl;
	std::cout << std::endl;
}

bool UserInterface::validateHashType(std::string &hash_type) {
	if(hash_type == "MD5" || hash_type == "SHA1" || hash_type == "SHA256" || hash_type == "SHA512") {
		return true;
	}
	else {
		std::cout << "An invalid hash type has been entered. This program supports MD5, SHA1, SHA256 and SHA512 type hashes." << std::endl;
		return false;
	}
}

void UserInterface::menu() {
	char choice;
	std::cout << "Please make a selection" << std::endl;
	std::cin >> choice;

	switch(choice) {
		case '1': {
			//bruteforce
			std::string userName;
			std::cout << " Enter the user name associated with the password you are attemptting to crack." << std::endl;
			std::cin >> userName;
			//BruteForce b(userName);
			break;
		}
		case '2': {
			//dictionary
			std::string filename;
			filename = "smallWordlist.txt";
			std::cout << std::endl;
			std::string givenHash;
			std::cout << "Enter a hash to begin the dictionary attack." << std::endl;
			std::cin >> givenHash;
			std::cout << std::endl;
			std::string hash_type;
			std::cout << "Enter the hash type." << std::endl;
			std::cin >> hash_type;
			std::cout << std::endl;
			validateHashType(hash_type);
			DictionaryAttack d(givenHash, hash_type);
			d.loadDictionary(filename);
			break;
		}
		case '3': {
			//usage
			printHelp();
			selection();
			break;
		}
		case '4': {
			//print help menu
			printHelp();
			selection();
			break;
		}
		case '5': {
			//quit program
			std::cout << " You are quitting the program." << std::endl;
			exit(EXIT_SUCCESS);
		}
	}
}


