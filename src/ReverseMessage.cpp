#include "../include/Obfuscate.h"

using namespace	Obfuscate;

std::string Obfuscator::Reverse(std::string message) {
	std::string newMessage;
	int n = 0;

	for (int i = message.length() - 1; i >= 0; i--) {
		newMessage.push_back('\0');
		newMessage[n] = message[i];
		n ++;
	}

	return newMessage;
}