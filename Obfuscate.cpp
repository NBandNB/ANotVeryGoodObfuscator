#pragma once

#include "Obfuscate.h"

using namespace Obfuscate;

char* Obfuscator::Obfuscate(int times, char* message) {
	char* encrypedMessage = message;


	for (int i = 0; i < times; i++) {
		encrypedMessage = Obfuscate::Obfuscator::ROT(77, encrypedMessage);
		encrypedMessage = Obfuscate::Obfuscator::Reverse(encrypedMessage);
		encrypedMessage = Obfuscate::Obfuscator::Binary(encrypedMessage);
	}
	

	return encrypedMessage;
}

