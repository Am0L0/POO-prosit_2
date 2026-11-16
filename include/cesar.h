#ifndef CESAR_H
#define CESAR_H

#include <string>

class Cesar {
private:
    int decalage;
public:
    Cesar(int nouveau_decalage) {
        decalage = ((nouveau_decalage % 26) + 26) % 26;
    }
    Cesar() {
        decalage = 1;
    }

    std::string Crypter(std::string message_original) {
        std::string message_chiffre;
        for (char lettre : message_original) {
            int code_ascii = int(lettre);
            if (code_ascii == 32) {
                message_chiffre += static_cast<char>(42);
            }
            else if (code_ascii >= 65 && code_ascii <= 90) {
                message_chiffre += static_cast<char>((code_ascii - 65 + decalage) % 26 + 65);
            }
            else if (code_ascii >= 97 && code_ascii <= 122) {
                message_chiffre += static_cast<char>((code_ascii - 97 + decalage) % 26 + 97);
            }
            else {
                message_chiffre += lettre;
            }
        }
        return message_chiffre;
    }

    std::string Decrypter(std::string message_chiffre) {
        std::string message_original;
        for (char lettre : message_chiffre) {
            int code_ascii = int(lettre);
            if (code_ascii == 42) {
                message_original += static_cast<char>(32);
            }
            else if (code_ascii >= 65 && code_ascii <= 90) {
                message_original += static_cast<char>((code_ascii - 65 - decalage + 26) % 26 + 65);
            }
            else if (code_ascii >= 97 && code_ascii <= 122) {
                message_original += static_cast<char>((code_ascii - 97 - decalage + 26) % 26 + 97);
            }
            else {
                message_original += lettre;
            }
        }
        return message_original;
    }
};
#endif