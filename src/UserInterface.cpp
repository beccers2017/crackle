/**
 * @file
 * @author Rebecca Donohoe
 * @version
 */

#include <iostream>
#include <stdlib.h>
#include "include/UserInterface.h"
//#include "BruteForce.h"
//#include "DictionaryAttack.h"
//#include <boost/program_options.hpp>

//using namespace boost::program_options;

UserInterface::UserInterface() {
	//default constructor
}
/**
void UserInterface::printScreen() {
	
}
*/
void UserInterface::printInfo() {
	
	std::cout << "Filename: " << __FILE__ << std::endl;
	std::cout << "Date: " << __DATE__ << std::endl;
	std::cout << "Time: " << __TIME__ << std::endl;
	std::cout << std::endl;
	std::cout << "     " << "***********************************************************************************" << std::endl;
	std::cout << "     " << "*                          Crackle: A Password Cracker                            *" << std::endl;
	std::cout << "     " << "*                                 Version 0.1.0                                   *" << std::endl;
	std::cout << "     " << "*                           Written by Rebecca Donohoe                            *" << std::endl;
	std::cout << "     " << "***********************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "             " << "This is a password cracking tool, intended for educational purposes." << std::endl;
	std::cout << "                     " << "This tool supports MD5, SHA1 and SHA2 hashes." << std::endl;
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
	std::cout << "        -h : Hash Type if known (optional)" << std::endl;
	std::cout << "        -o : write results to output file" << std::endl; //again add more usage information
	std::cout << "        -l : Include a log file" << std::endl;
	std::cout << std::endl;
	std::cout << "    Examples: " << std::endl;
	std::cout << "        ./crackle -d" << std::endl;
	std::cout << "        ./crackle -c /usr/csci3010-personal-project/Wordlists/parsedWordlist.txt" << std::endl;
	std::cout << std::endl;
}

//other options -- amount of time to run for, verbose output, load a saved file from previous session, auto-saving at intervals
/**
 * Could also add an option for command line usage only or easier usage where it walks you through the process of running the program
 */

/**
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
			BruteForce b(userName);
			break;
			
		case 2: 
			//dictionary
			std::string givenHash;
			std::cout << "Enter a hash to begin the dictionary attack." << std::endl;
			std::cin >> givenHash;
			DictionaryAttack  d(givenHash);
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
			//is there a way to use this without having to declare entire library?
			exit(EXIT_SUCCESS);
	}
}
*/
/**
void UserInterface::readConsoleInput() {
	
}
*/
//clear screen function or keep this information displayed all the time -- maybe this is the purpose of print screen since it is currently unused
//if something is missing print the help message
