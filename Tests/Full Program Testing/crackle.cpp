/**
 * @file crackle.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include "UserInterface.h"

int main(int argc, char *argv[]) {
	//debugging line
	//std::cout << "There were " << argc << " arguments entered" << std::endl;
	UserInterface u;
	if(argc < 2) {
		u.printHelp();
	} else {
		u.parse_cmd(argc, argv);
	}
	//u.printInfo();
	//u.selection();
	//u.printHelp();
}