#include "Obfuscate.h"

using namespace Obfuscate;

char* Obfuscator::Binary(char* message) {
	static std::string newMessage;
	for (int i = 0; i < strlen(message); i++) {
		int n = (int)message[i];
		for (int i = 0; i < 8; i++)
		{
			newMessage.append(std::to_string(n % 2));
			n = n / 2;
		}
		newMessage.append("\n");
	}



	char* newNewMessage = (char*)newMessage.c_str();
	return newNewMessage;
}
