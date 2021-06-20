#include "Obfuscate.h"

using namespace	Obfuscate;

std::string Obfuscator::Reverse(std::string message) {
	static std::string newMessage;
	static int n = 0;

	for (int i = message.length() - 1; i >= 0; i--) {
		newMessage.push_back((char)"\0");
		newMessage[n] = message[i];
		n += 1;
	}

	return newMessage;
}