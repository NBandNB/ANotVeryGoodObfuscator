#include "Obfuscate.h"

using namespace Obfuscate;

std::string Obfuscator::Binary(std::string message) {
	static std::string newMessage;
	for (int i = message.length()-1; i >= 0; i--) {
		int n = message[i];
		for (int i = 0; i < 8; i++)
		{
			char currentChar = (char)(48 + (n % 2));
			newMessage.append(1,currentChar);
			n = n / 2;
		}
		newMessage.append((std::string)"\n");
	}

	return newMessage;
}

std::string Obfuscator::ReverseBinary(std::string message) {
	static std::string newMessage = message;
	std::string newNewMessage;
	for (long long i = (message.length() / 9)-1; i >= 0; i--) {
		std::string currentBin = newMessage.substr(i * (long long)9, (i * (long long)9) + (long long)8);
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
		newNewMessage.push_back(currentCharecter);
	}

	static std::string finalMessage(newNewMessage.begin(), newNewMessage.end());
	return finalMessage;
}

