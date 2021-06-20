#pragma once

#include "Obfuscate.h"

using namespace Obfuscate;

std::string Obfuscator::Obfuscate(int times, std::string message) {
	std::string encrypedMessage = message;


	for (int i = 0; i < times; i++) {
		encrypedMessage = Obfuscate::Obfuscator::ROT(77, encrypedMessage);
		encrypedMessage = Obfuscate::Obfuscator::Reverse(encrypedMessage);
		encrypedMessage = Obfuscate::Obfuscator::Binary(encrypedMessage);
	}
	

	return encrypedMessage;
}

std::string Obfuscator::Deobfuscate(int times, std::string message) {
	std::string decrypedMessage = message;


	for (int i = 0; i < times; i++) {
		decrypedMessage = Obfuscate::Obfuscator::ReverseBinary(decrypedMessage);
		decrypedMessage = Obfuscate::Obfuscator::Reverse(decrypedMessage);
		decrypedMessage = Obfuscate::Obfuscator::RROT(77, decrypedMessage);
	}


	return decrypedMessage;
}