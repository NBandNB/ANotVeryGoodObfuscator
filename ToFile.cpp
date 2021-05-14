#include "FileHandler.h"

using namespace std;

void Files::writeToFile(std::string file, std::string message) {
	std::ofstream fileOut;
	fileOut.open(file);
	fileOut << message;
	fileOut.close();
}

string Files::readFromFile(std::string file) {
	std::ifstream fileIn;
	fileIn.open(file);
	std::string textIn;
	copy(istream_iterator<char>{ fileIn >> noskipws }, {}, back_inserter(textIn));
	fileIn.close();
	remove(file.c_str());
	return textIn;
}