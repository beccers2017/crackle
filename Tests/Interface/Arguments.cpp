#include "Arguments.h"
#include <string>

Arguments::Arguments(int argc, char *argv[]) {
	for(int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if(arg[0] == '-' && argc > (i + 1)) {
			args[arg.at(1)] == argv[++i];
		}
	}
}

bool Arguments::containsKey(char key) {
	return args.find(key) != args.end();
}

std::string Arguments::getValue(char key) {
	return containsKey(key) ? args.find(key)->second : "";
}