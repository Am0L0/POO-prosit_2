#ifndef XOR_H
#define XOR_H

#include <string>
#include <iostream>

class XOR {
private:
    std::string cle;
public:
    XOR(std::string n_cle) {
        if (n_cle.empty()) {
            throw std::runtime_error("La cle XOR ne peut pas etre vide");
        }
        cle = n_cle;
    }
    std::string Crypter(std::string message) {
        int len_mess = message.size();
        int len_cle = cle.size();
        for (int i = 0; i < len_mess; i++) {
            message[i] = message[i] ^ cle[i % len_cle];
        }
        return message;
    }
};
#endif