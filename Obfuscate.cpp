#pragma once

#include "Obfuscate.h"

using namespace Obfuscate;

char* Obfuscator::Obfuscate(int times, char* message) {
    char* encrypedMessage = message;
    encrypedMessage = Obfuscate::Obfuscator::ROT(77, encrypedMessage);

    for (int i = 0; i < times; i++) {
        
    }
    
    encrypedMessage = Obfuscate::Obfuscator::Reverse(encrypedMessage);

    return encrypedMessage;
}

