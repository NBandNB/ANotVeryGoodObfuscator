#include "FileHandler.h"

using namespace std;

void Files::writeToFile(std::string file, std::string message) {
	std::ofstream fileOut;
	fileOut.open(file);
	fileOut << message;
	fileOut.close();
}

string Files::readFromFile(std::string file) {
    std::ifstream in(file, std::ios::in | std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }
    return "BADFILE";
}

bool Files::badText(std::string message) {
    if (message == "BADFILE") {
        std::cout << "The file does not exist!"; 
        return true;
    }
    else if (message.length() == 0) {
        std::cout << "The file is empty!";
        return true;
    }
    else
    {
        return false;
    }
}