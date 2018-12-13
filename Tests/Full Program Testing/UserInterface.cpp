/**
 * @file UserInterface.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "termcolor/termcolor.hpp"
#include "UserInterface.h"
#include "BruteForce.h"
#include "DictionaryAttack.h"


const std::string DEFAULT_DICTIONARY = "parsedWordlist.txt";
const std::string DEFAULT_OUTPUT_FILE = "brute.txt";
const std::string version = "Crackle version 0.1.0";
static const int maxPasswordSize = 8;

UserInterface::UserInterface() {
	//default constructor
}

void UserInterface::parse_cmd(int argc, char *argv[]) {
	//std::string bruteforce;
	//std::string dictionary;
	
	while((argv[1] == "bruteforce") && (argc = 6)) {
		if((argv[2] = "-u") && (argv[4] == "-p") && (argv[6] == "-o")) {
			std::string userName = argv[3];
			int password_length = atoi(argv[5]);
			validatePasswordSize(password_length);
			BruteForce b(userName, password_length);
			std::string filename = DEFAULT_OUTPUT_FILE;
			b.loadWriteFile(filename);
		}
	}

	while((argv[1] == "bruteforce") && (argc = 7)) {
		if((argv[2] = "-u") && (argv[4] == "-p") && (argv[6] == "-o")) {
			std::string userName = argv[3];
			int password_length = atoi(argv[5]);
			validatePasswordSize(password_length);
			BruteForce b(userName, password_length);
			std::string filename = argv[7];
			b.loadWriteFile(filename);
		}
	}
	while((argv[1] == "dictionary") && (argc = 6)) {
			if((argv[2] == "-g") && (argv[4] = "-t") && (argv[6] == "-d")) {
				std::string givenHash = argv[3];
				std::string hash_type = argv[5];
				validateUppercaseString(hash_type);
				//validateHashType(hash_type);
				DictionaryAttack d(givenHash, hash_type);
				std::string filename = DEFAULT_DICTIONARY;
				d.loadDictionary(filename);
			}
	}
	while((argv[1] == "dictionary") && (argc = 7)) {
		if((argv[2] == "-g") && (argv[4] = "-t") && (argv[6] == "-c")) {
			std::string givenHash = argv[3];
			std::string hash_type = argv[5];
			validateUppercaseString(hash_type);
			//validateHashType(hash_type);
			DictionaryAttack d(givenHash, hash_type);
			std::string filename = argv[7];
			d.loadDictionary(filename);
		}
	}
	if(argc = 2) {
		if(argv[1] == "-v") {
			std::cout << version << std::endl;
		}
		else if(argv[1] == "-i") {
			printInfo();
		}
		else if(argv[1] == "-h") {
			printHelp();
		}
		else if(argv[1] == "-e") {
			selection();
		}
		else if(argv[1] == "-q") {
			questions();
		}
		else {
			std::cout << "An invalid option has been entered" << std::endl;
			printHelp();
		}
	}

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

void UserInterface::printHelp() { 
	std::cout << std::endl;
	std::cout << "Usage: ./crackle [attack type] [options] ... " << std::endl;
	std::cout << std::endl;
	//std::cout << "    Options:" <<std::endl;
	std::cout << "The following options are associated with bruteforce attack:" << std::endl;
	std::cout << std::endl;
	std::cout << "        -u [username]         Username for bruteforce attack" << std::endl;
	std::cout << "        -p [password length]  Length of password you want generate" << std::endl;
	std::cout << "        -o [output file]      Output file for generated passwords (Specifying the output file is optional. Use -o to use default out file)" << std::endl;
	std::cout << std::endl;
	std::cout << "The following options are associated with dictionary attack:" << std::endl;
	std::cout << std::endl;
	std::cout << "        -g [hash]             Hash for dictionary attack" << std::endl;
	std::cout << "        -t [hash-type]        Type of hash" << std::endl;
	std::cout << "        -d                    Use default dictionary file" << std::endl;
	std::cout << "        -c [path to file]     Use custom dictionary file" << std::endl;
	std::cout << std::endl;
	std::cout << "Other options:" << std::endl;
	std::cout << std::endl;
	std::cout << "        -v                    Print program version" << std::endl;
	std::cout << "        -i                    Print program information" << std::endl;
	std::cout << "        -e                    Easy mode" << std::endl;
	std::cout << "        -q                    Have questions or found bugs?" << std::endl;
	std::cout << "        -h                    Produce help information" << std::endl;
	std::cout << std::endl;
	std::cout << "    Examples: " << std::endl;
	std::cout << "        ./crackle bruteforce -u [username] -p [password length] -o" << std::endl;
	std::cout << "        ./crackle bruteforce -u [username] -p [password length] -o [output file]" << std::endl;
	std::cout << "        ./crackle dictionary -g [hash] -t [hash-type] -d" << std::endl;
	std::cout << "        ./crackle dictionary -g [hash] -t [hash-type] -c [path to file]" << std::endl;
	std::cout << std::endl;
}

std::string UserInterface::validateUppercaseString(std::string hash_type) {
	std::transform(hash_type.begin(), hash_type.end(), hash_type.begin(), ::toupper);
	validateHashType(hash_type);
}

bool UserInterface::validateHashType(std::string &hash_type) {
	if(hash_type == "MD5" || hash_type == "SHA1" || hash_type == "SHA256" || hash_type == "SHA512") {
		return true;
	}
	else {
		std::cout << "An invalid hash type has been entered. This program supports MD5, SHA1, SHA256 and SHA512 type hashes." << std::endl;
		return false;
		exit(0);
	}
}

bool UserInterface::validatePasswordSize(int password_length) {
	if(password_length > maxPasswordSize) {
		std::cout << "The maximum password length this program currently supports is 8 characters long" << std::endl;
		return false;
		exit(0);
	}
	else if(password_length <= maxPasswordSize) {
		return true;
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
			
			std::cout << "Specify the length of password you would like to generate. The value must be at least 4 characters long ";
			std::cout << " and a maximum size of 8 characters" << std::endl;
			int password_length;
			cin >> password_length;
			validatePasswordSize(password_length);
			
			std::string filename;
			filename = "brute.txt";
			
			BruteForce b(userName, password_length);
			b.loadWriteFile(filename);
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
			validateUppercaseString(hash_type);
			//validateHashType(hash_type);
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

void UserInterface::questions() {
	std::cout << "To ask any questions or report bugs, email rebecca.donohoe@colorado.edu" << std::endl;
}
