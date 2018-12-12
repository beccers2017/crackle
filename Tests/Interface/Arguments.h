#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <iostream>
#include <string>
#include <unordered_map>

class Arguments {
	public:
		Arguments(int count, char *list[]);
		bool containsKey(char);
		std::string getValue(char);
	private:
		std::unordered_map<char, std::string> args;
};
#endif