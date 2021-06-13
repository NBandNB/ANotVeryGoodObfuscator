#include "Obfuscate.h"

using namespace Obfuscate;

char* Obfuscator::ROT(int rotations,char* message) {
	static std::vector<char> newMessage;
	for (int i = 0; i < strlen(message); i++) {
		newMessage.push_back((char)"\0");
		newMessage[i] = (char) (message[i] + rotations);
		newMessage[i] = (char)( newMessage[i] + 128);
	}

	char* newNewMessage = newMessage.data();

	for (int i = strlen(message); i < strlen(newNewMessage); ++i)
		newNewMessage[i] = NULL;
	return newNewMessage;
}
