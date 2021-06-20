#include "Obfuscate.h"

using namespace Obfuscate;

std::string Obfuscator::ROT(int rotations, std::string message) {
	static std::string newMessage;
	for (int i = 0; i < message.length(); i++) {
		newMessage.push_back(NULL);
		newMessage[i] = (char) (message[i] + rotations)+128;
	}

	return newMessage;
}

std::string Obfuscator::RROT(int rotations, std::string message) {
	static std::string newMessage;
	for (int i = 0; i < message.length(); i++) {
		newMessage.push_back(NULL);
		newMessage[i] = (char)(message[i] - rotations)-128;
	}


	return newMessage;
}