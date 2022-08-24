#include "../include/Obfuscate.h"

using namespace Obfuscate;

std::string Obfuscator::ROT(char rotations, std::string message) {
	std::string newMessage;
	for (int i = 0; i < message.length(); i++) {
		newMessage.push_back('\0');
		newMessage[i] = message[i] + rotations+128;
	}

	return newMessage;
}

std::string Obfuscator::RROT(char rotations, std::string message) {
	std::string newMessage;
	for (int i = 0; i < message.length(); i++) {
		newMessage.push_back('\0');
		newMessage[i] = message[i] - rotations-128;
	}


	return newMessage;
}