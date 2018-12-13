#include <iostream>
#include <string>


const std::string DEFAULT_DICTIONARY = "parsedWordlist.txt";
const std::string DEFAULT_OUTPUT_FILE = "brute.txt";

oid UserInterface::parse_cmd(int argc, char *argv[]) {
	for(int i = 0; i < argc; i++) {
		if(i + 1 != argc) {
			if(argv[i] == "-v") {
				std::cout << version << std::endl;
			}
			else if(argv[i] == "-i") {
				printInfo();
			}
			else if(argv[i] == "-h") {
				printHelp();
			}
			else if(argv[i] == "-e") {
				selection();
			}
			else if(argv[i] == "-q") {
				questions();
			}
			
		}
	}
	
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
	
	char* flag = argv[1];
	switch(flag) {
		case '-v': {
			std::cout << version << std::endl;
			break;
		}
		case '-i': {
			printInfo();
			break;
		}
		case '-h': {
			printHelp();
			break;
		}
		case '-e': {
			selection();
			break;
		}
		case '-q': {
			questions();
			break;
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