#include <iostream>
#include <string>


const std::string DEFAULT_DICTIONARY = "parsedWordlist.txt";
const std::string DEFAULT_OUTPUT_FILE = "brute.txt";

void parse_cmd(int argc, char *argv[]) {
	std::string bruteforce;
	std::string dictionary;
	
	while((argv[1] == "bruteforce") && (argc = 6)) {
		if((argv[2] = "-u") && (argv[4] == "-p") && (argv[6] == "-o")) {
			userName = argv[3];
			password_length = argv[5];
			validatePasswordSize(password_length);
			filename = DEFAULT_OUTPUT_FILE;
		}
	}

	while((argv[1] == "bruteforce") && (argc = 7)) {
		if((argv[2] = "-u") && (argv[4] == "-p") && (argv[6] == "-o")) {
			userName = argv[3];
			password_length = argv[5];
			validatePasswordSize(password_length);
			filename = argv[7];
		}
	}
	while((argv[1] == "dictionary") && (argc = 6)) {
			if((argv[2] == "-g") && (argv[4] = "-t") && (argv[6] == "-d")) {
				givenHash = argv[3];
				hash_type = argv[5];
				validateHashType(hash_type);
				DictionaryAttack d(givenHash, hash_type);
				filename = DEFAULT_DICTIONARY;
				d.loadDictionary(filename);
			}
	}
	while((argv[1] == "dictionary") && (argc = 7)) {
		if((argv[2] == "-g") && (argv[4] = "-t") && (argv[6] == "-c")) {
			givenHash = argv[3];
			hash_type = argv[5];
			validateHashType(hash_type);
			DictionaryAttack d(givenHash, hash_type);
			filename = argv[7];
			d.loadDictionary(filename);
		}
	}
	
	while(argc = 2) {
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
	
	/**
	for(int i = 0; i < argc; ++i) {
		std::cout << argv[i] << std::endl;
	}
	*/
}




int main(int argc, char *argv[]) {
	//debugging line
	std::cout << "There were " << argc << " arguments entered" << std::endl;
	//if(argc < 2) {
		//std::cout << "Not enough arguments to run crackle" << std::endl;
	//	u.printInfo();
	//}
	//UserInterface u;
	//u.printInfo();
	parse_cmd(argc, argv);
}