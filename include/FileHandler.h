#pragma once

#include <fstream>
#include "Main.h"

class Files
{
public:
	static void writeToFile(std::string file, std::string message);
	static std::string readFromFile(std::string file);
	static bool badText(std::string message);

};
