/**
 * @file crackle.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
#include "UserInterface.h"

int main(int argc, char *argv[]) {
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



/*
namespace po = boost::program_options;

void show_help(const po::options_description& desc, const std::string& topic = "") {
	std::cout << desc << '\n';
	if(topic != "") {
		std::cout << "You asked for help on: " << topic << '\n';
	}
	exit(EXIT_SUCCESS);
}

void process_program_options(const int argc, const char *const argv[]) {
	po::options_description desc("Allowed options");
	desc.add_options()
		(
			"help,h",
			po::value< std::string >()
				->implicit_value("")
				->notifier(
					[&desc](const std::string& topic) {
						show_help(desc,topic);
					}
				),
				"Show help"
		)
	;
	
	if(argc == 1) {
		show_help(desc);
	}

	po::variables_map args;
	
	try {
		po::store(
			po::parse_command_line(argc, argv, desc),
			args
			);
	}
	catch(po::error const& e) {
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
	po::notify(args);
	return;
}
*/




