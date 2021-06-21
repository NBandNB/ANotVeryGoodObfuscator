#include "Main.h"

std::string inFile = "in.txt";
std::string outFile = "out.txt";
bool removeInFile = false;
bool isGraphical = true; 

int main(int argc, char** argv) {

	std::cout << "Welcome to the ANotVeryGoodObfuscator please remember that it lives up to its name.\nIt will not hide any information, do not use this for security.\n\n\t-LotsOfBlochs" << std::endl;

	if (argc == 0) {
		std::cout << " Please enter a valid number of arguments\n For more help try: \n \"Obfuscate -h\"" << std::endl;
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
		auto app = Gtk::Application::create("org.gtkmm.example");

		//Shows the window and returns when it is closed.
		return app->make_window_and_run<GUI>(argc, argv);
	}
	else if (!isGraphical) {
		std::string message = Files::readFromFile(inFile);
		if (Files::badText(message)) {
			std::exit(EXIT_FAILURE);
		}
		message = Obfuscate::Obfuscator::Obfuscate(1, message);
		Files::writeToFile(outFile, message);
		if (removeInFile) {
			remove(inFile.c_str()); 
		}
		//std::abort();
		std::exit(EXIT_SUCCESS);
	}
}