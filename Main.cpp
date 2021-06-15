#include "Main.h"


std::string inFile = "in.txt";
std::string outFile = (char*)"out.txt";
bool isGraphical = false; 
bool removeInFile = false;


int main(int argc, char** argv) {


	if (argc == 0) {
		std::cout << " Please enter a valid number of arguments\n For more help try: \n \"Obfuscate -h\"";
		std::exit(EXIT_FAILURE);
	}

	

	else {
		for (int i = 0; i < sizeof(argv); i++) {
			if (argv[i] == "-in" || argv[i] == "--FileIn") {
				inFile.assign(argv[i + 1]);
			}
			else if (argv[i] == "-out" || argv[i] == "--FileOut") {
				outFile.assign(argv[i + 1]);
			}
			else if (argv[i] == "-g") {
				isGraphical = true; 
			}
			else if (argv[i] == "-r") {
				removeInFile = true;
			}
		}
	}
	if (isGraphical) {
		
	}
	else if (!isGraphical) {
		std::string message = Files::readFromFile(inFile);
		if (Files::badText(message)) {
			std::exit(EXIT_FAILURE);
		}
		message = Obfuscate::Obfuscator::Obfuscate(1, (char*)message.c_str());
		Files::writeToFile(outFile, message);
		if (removeInFile) {
			remove(inFile.c_str()); 
		}
		//std::abort();
		std::exit(EXIT_SUCCESS);
	}
}