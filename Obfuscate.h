#pragma once

#include <stdio.h>
#include "Main.h"

namespace Obfuscate {
	class Obfuscator
	{
	public:
		static std::string Obfuscate(int times, std::string message);
		static std::string Deobfuscate(int times, std::string message);
		static std::string RROT(int rotations, std::string message);
		static std::string ROT(int rotations, std::string message);
		static std::string Reverse(std::string message);
		static std::string ReverseBinary(std::string message);
		static std::string Binary(std::string message);
	};

}


