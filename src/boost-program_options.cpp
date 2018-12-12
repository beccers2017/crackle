/**
 * Using boost filesystem to work with paths to files (i.e.,dictionary files)
 */

/**
 * Boost Notes
 * Add the definition of each command line argument to your options
 * description object using one of two formats:
 * ("long-name, short name", "Description of argument") for flag values
 * or
 * ("long-name, short-name", <data-type>, "Description of argument") for
 * arguments with values
 * 
 * Arguments with multi-values must be vectors
 */


//compile using the flag -lboost_program_options (i.e., g++ main.cpp -lboost_program_options)

#include <cstdlib>
#include <iostream>
#include <boost/program_options.hpp>
//#include <boost/filesystem.hpp>

//namespace fs = boost::filesystem;
namespace po = boost::program_options;

const std::string version = "Crackle version 0.1.0";

void show_help(const po::options_description& desc, const std::string& topic = "") {
	std::cout << desc << '\n';
	if(topic != "") {
		std::cout << "You asked for help on: " << topic << '\n';
	}
	exit(EXIT_SUCCESS);
}

void process_program_options(const int argc, const char *const argv[]) {
	po::options_description desc("Options");
	desc.add_options()
		("help, h", "Show help message")
		("version, v", "Show version number")
		("username, u", po::value<std::vector<std::string>>(), "Give a user name for brute-force attack")
		("hash, h", po::value<std::vector<std::string>>(), "Given a hash for dictionary attack")
		("type, t", po::value<std::vector<std::string>>(), "Specify the type of hash for dictionary attack")
		("output, o", po::value<std::vector<std::string>>(), "Write data to an output file") 
		("custom-dictionary", po::value<std::vector<std::string>>()->composing(), "Specify a custom dictionary file path")
		("default-dictionary", po::value<std::vector<std::string>>(), "Use the built in dictionary")
	;
	
	//po::positional_options_description p;
	//p.add("custom-dictionary", -1);
	
	if(argc == 1) {
		show_help(desc);
	}
	
	po::variables_map vm;
	
	try {
		po::store(
			po::parse_command_line(argc, argv, desc), vm);
			//po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
	}
	catch(po::error const& e) {
		std::cerr << e.what() << '\n';
		exit(EXIT_FAILURE);
	}
	po::notify(vm);
	
	if(vm.count("help")) {
		std::cout << desc << std::endl;
	}
	if(vm.count("version")) {
		std::cout << version << std::endl;
	}
	if(vm.count("username")) {
		std::cout << "The user name entered was " << vm["username"].as<std::string>() << std::endl;
	} else {
		std::cout << "A user name was not entered" << std::endl;
	}
	if(vm.count("hash")) {
		std::cout << std::endl;
	}
}

int main(int argc, char *argv[]) {
	process_program_options(argc, argv);
	//return 0;
}


