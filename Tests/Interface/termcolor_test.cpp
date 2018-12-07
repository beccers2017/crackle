#include <iostream>
#include "termcolor/termcolor.hpp"

int main() {
	std::cout << termcolor::green << "Launching Dictionary Attack" << std::endl;
	std::cout << termcolor::reset << "Launching Dictionary Attack" << std::endl;
	std::cout << termcolor::bold << "Launching Dictionary Attack" << std::endl;
	std::cout << termcolor::yellow << "Launching Dictionary Attack" << std::endl;
	std::cout << termcolor::bold << termcolor::magenta << "Launching Dictionary Attack" << std::endl;
	return 0;
}