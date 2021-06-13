#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

namespace Obfuscate {
	class Obfuscator
	{
	public:
		static char* Obfuscate(int times, char* message);
		static char* ROT(int rotations, char* message);
		static char* Reverse(char* message);
		static char* Binary(char* message);
	};

}


