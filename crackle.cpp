/**
 * @file crackle.cpp
 * @author Rebecca Donohoe
 * @version 0.1.0
 */

#include <iostream>
//#include "include/BruteForce.h"
//#include "include/DictionaryAttack.h"
//#include "src/UserInterface.cpp"
#include "include/UserInterface.h"

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


int main() {

/*
int main(int argc, char *argv[]) {
	for(int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if(arg[0] == '-' && argc > (i + 1)) {
			args[arg.at(1)] = argv[++i];
		}
	}
	*/
	
	
	
	
	
	UserInterface u;
	u.printInfo();
	u.printHelp();
}

