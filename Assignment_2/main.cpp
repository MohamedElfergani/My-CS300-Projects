#include <iostream>
#include "SLLString.h"

int main() {

	SLLString str("Hello world!");

	SLLString newStr;

	newStr = str; //calls assignment operator 

	newStr += SLLString(" CS@BC");

	newStr[6] = 'W';

	std::cout << newStr << std::endl; // Hello World! CS@BC

	std::cout << newStr.length() << std::endl; //18

	int loc = newStr.findSubstring("World");

	std::cout << loc << std::endl; // 6

	newStr.erase('l'); //erase the letter l.

	std::cout << newStr << std::endl; // Heo Word! CS@BC

	newStr.erase('C');

	std::cout << newStr << std::endl; // Heo Word! S@B

	return 0;
}