#include "../include/Obfuscate.h"

using namespace Obfuscate;

std::string Obfuscator::Binary(std::string message) {
	std::string newMessage;
	for (char t : message) {
		for (int n = 0; n < 8; n++)
		{
			char currentChar = (char)('0' + (t % 2));
			newMessage.append(1,currentChar);
            t /= 2;
		}
		newMessage.append((std::string)"\n");
	}

	return newMessage;
}

std::string Obfuscator::ReverseBinary(std::string message) {
	std::string newMessage;
	for (long long i = 0; i < message.length(); i+=9) {
		std::string currentBin = message.substr(i, i + (long long)8);
		char* currentCharBin = (char*)currentBin.c_str();
		int currentChar = 1 * (currentCharBin[0] - 48);
		currentChar += 2 * (currentCharBin[1] - 48);
		currentChar += 4 * (currentCharBin[2] - 48);
		currentChar += 8 * (currentCharBin[3] - 48);
		currentChar += 16 * (currentCharBin[4] - 48);
		currentChar += 32 * (currentCharBin[5] - 48);
		currentChar += 64 * (currentCharBin[6] - 48);
		currentChar += 128 * (currentCharBin[7] - 48);
		char currentCharecter = (char)currentChar;
        newMessage.push_back(currentCharecter);
	}
	return newMessage;
}

