#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "Main.h"

std::string inFile = "in.txt";
std::string outFile = (char*)"out.txt";

int main(int argc, char** argv) {
	if (argc == 0) {
		printf(" Please enter a valid number of arguments\n For more help try: \n \"Obfuscate -h\"");
		return 1;
	}
	else {
		for (int i = 0; i < sizeof(argv); i++) {
			if (argv[i] == "-in" || argv[i] == "--FileIn") {
				inFile.assign(argv[i + 1]);
			}
			else if (argv[i] == "-out" || argv[i] == "--FileOut") {
				outFile.assign(argv[i + 1]);
			}
		}
	}
	
	
	if (std::experimental::filesystem::exists(inFile)) {
		std::string message = Files::readFromFile(inFile);
		message = Obfuscate::Obfuscator::Obfuscate(1, (char*)message.c_str());
		Files::writeToFile(outFile, message);
	}
	else {
		std::cout << "File does not exist!";
	}
}