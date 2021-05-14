#include "Obfuscate.h"

using namespace std;

using namespace Obfuscate;

char* Obfuscator::ROT(int rotations,char* message) {
    static vector<char> newMessage;
    for (int i = 0; i < strlen(message); i++) {
        newMessage.push_back((char)"\0");
        newMessage[i] = (char) (message[i] + rotations);
        if (int(message[i]) > 127) {
            newMessage[i] = (char)( message[i] % 127);
        }
    }
    char* newNewMessage = newMessage.data();
    for (int i = strlen(message); i < strlen(newNewMessage); ++i)
        newNewMessage[i] = NULL;
    return newNewMessage;
}
