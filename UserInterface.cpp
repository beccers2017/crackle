/**
 * @file UserInterface.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include "include/UserInterface.h"

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
	std::cout << "             " << "This is a password cracking tool, intended for educational purposes." << std::endl;
	std::cout << "                     " << "This tool supports MD5, SHA1, SHA256, and SHA 512 hashes." << std::endl;
	std::cout << "          " << "Passwords can be cracked using a brute-force attack or a dictionary attack." << std::endl;
	std::cout << std::endl;
	std::cout << " Please select an option: " << std::endl;
	std::cout << "   [1] Brute-Force Attack" << std::endl;
	std::cout << "   [2] Dictionary Attack" << std::endl;
	std::cout << "   [3] Print Usage" << std::endl;
	std::cout << "   [4] Print Help Menu" << std::endl;
	std::cout << "   [5] Quit Program" << std::endl;
	//menu();
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

void UserInterface::menu() {
	int choice;
	std::cout << "Please make a selection" << std::endl;
	std::cin >> choice;

	switch(choice) {
		case 1:
			//bruteforce
			std::string userName;
			std::cout << "Enter the user name associated with the password you are attemptting to crack." << std::endl;
			std::cin >> userName;
			//BruteForce b(userName);
			break;
			
		case 2: 
			//dictionary
			std::string givenHash;
			std::cout << "Enter a hash to begin the dictionary attack." << std::endl;
			std::cin >> givenHash;
			DictionaryAttack d(givenHash);
			break;
		case 3:
			//usage
			printHelp();
			break;
		case 4:
			//print help menu
			printHelp();
			break;
		case 5:
			//quit program
			exit(EXIT_SUCCESS);
	}
}


