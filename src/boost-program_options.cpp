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
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
namespace po = boost::program_options;

const std::string version = "Crackle version 0.1.0";

/**
void UserInterface::printHelp() {
	po::options_description desc{"Options"};
	desc.add_options()
		("default-dictionary,d", "Use default dictionary")
		("custom-dictionary,c", "Use a custom dictionary")
		("user-name,u", po::value<std::vector<std::string>>(), "Gives the user name associated with the password")
		("hash-type,h", po::value<std::vector<std::string>>(), "Specifies the hash type")
		("hash,g", po::value<std::vector<std::string>>(), "Enter a hash to crack")
		("output-file,o", po::value<std::vector<std::string>>(), "Names the output file")
		("log-file,l", "Create a log file");
		("run-time,r", po::value<std::vector<std::string>>(), "Specify a time for the program to run for")
*/

void process_program_options(const int argc, const char *const argv[]) {
	po::options_description desc("Options");
	desc.add_options()
		("help, h", "Show help message")
		("version, v", "Show version number")
		("username, u", po::value<std::vector<std::string>>(username), "Give a user name for brute-force attack") //username might need to be changed because its a private member
		("hash, h", po::value<std::vector<std::string>>(given_hash), "Given a hash for dictionary attack")
		("type, t", po::value<std::vector<std::string>>(hashType), "Specify the type of hash for dictionary attack") //same as above for hashType
		("output,o", po::value<std::vector<std::string>>(), "Write data to an output file") //will need to use filesystem here?
		("custom-dictionary, c", po::value<std::vector<std::string>>()->default_value("parsedWordlist.txt"), "Specify a custom dictionary file")
	;
	
	if(argc == 1) {
		show_help(desc);
	}
	
	po::variables_map vm;
	
	try {
		po::store(
			po::parse_command_line(argc, argv, desc), vm);
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
		std:: 
	}
}


po::positional_options_description p;
p.add

/*
void walk_dirs(const std::vector<std::string>& dirs) {
	size_t n_files(0);
	for(const auto& dir : dirs) {
		try {
			auto walker = fs::recursive_directory_iterator(fs::path(dir));
			for(const auto& entry:walker) {
				if(fs::is_regular_file(entry)) {
					n_files += 1;
				}
			}
		}
		catch(const std::exception& x) {
			std::cerr << "Error accessing " << dir << "\n\t" << x.what() << '\n';
		}
	}
	std::cout << n_files << " files\n";
}

int main(int argc, char *argv[]) {
	process_program_options(argc, argv);
	//return 0;
}
*/
/**
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>

namespace fs = boost::filesystem;

int main(int argc, char** argv) {
	fs::path full_path(fs::initial_path<fs::path>());
	full_path = fs::system_complete(fs::path(argv[0]));
	std::cout << full_path << std::endl;
	
	//without file name
	std::cout << full_path.stem() << std::endl;
	return 0;
}
*/

/*
namespace po = boost::program_options;
namespace fs = boost::filesystem;

void make_path_absolute(
    const std::string& name,
    po::variables_map& vm,
    const fs::path& root)
{
    if (vm.count(name) > 0) {
        const auto path = vm[name].as<fs::path>();

        if (!path.empty()) {
            vm.at(name).value() = fs::absolute(path, root);
        }
    }
}

/**
 * The call makes the path absolute relative to the specified root
 * In this first case the root is the execution directory, in the 
 * second case, it's the configuration file parent folder
 */
/*
namespace po = boost::program_options;
namespace fs = boost::filesystem;

po::variables_map vm;

po::store(po::parse_command_line(argc, argv, options), vm);
make_path_absolute("foo.path", vm, fs::current_path());

po::store(po::parse_config_file(ifs, options, true), vm);
make_path_absolute("foo.path", vm, configuration_file.parent_path());

po::notify(vm);
*/