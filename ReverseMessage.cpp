#include "Obfuscate.h"

using namespace	Obfuscate;

char* Obfuscator::Reverse(char* message) {
	static std::vector<char> newMessage;
	static int n = 0;

	for (int i = strlen(message) - 1; i >= 0; i--) {
		newMessage.push_back((char)"\0");
		newMessage[n] = message[i];
		n += 1;
	}

	char* newNewMessage = newMessage.data();
	for (int i = strlen(message); i < strlen(newNewMessage); ++i)
		newNewMessage[i] = NULL;
	return newNewMessage;
}