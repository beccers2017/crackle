#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <sys/param.h>
#include <unistd.h>
#include <cerrno>

bool validateTest();

void testPassword(std::string user, std::string password) {
	/* Concatenate multiple strings together to firm the long command string? */
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
	
	//debugging line
	std::cout << "Before validateTest" << std::endl;
	
	bool isValid;
	isValid = validateTest();
	if(isValid == true) {
		std::cout << "This program was able to log in using the password: " << password << std::endl;
		exit(0);
	}
}

bool validateTest() {
	std::string str1 = "Login Successful";
	//std::string str2 = "Login unsuccessful";
	std::string valid;
	
	std::string directory = "/home/rebecca/";
	chdir(directory.c_str());
	
	//debugging line
	std::cout << "Inside validateTest" << std::endl;
	
	std::string command = "cat /opt/lampp/htdocs/Login-Test/file.txt";
	valid = std::system(command.c_str());
	
	if(valid == str1) {
		std::cout << "Login was successful" << std::endl;
		return true;
	}
	else {
		return false;
	}
	
	/**
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
	*/
}

int main() {
	std::string user = "user3";
	std::string password = "password1";
	testPassword(user, password);
}