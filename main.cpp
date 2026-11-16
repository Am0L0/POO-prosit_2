#include "include/texte.h"
#include "include/cesar.h"
#include "include/XOR.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

int main() {
    int mode, met, cle, taille;
    std::string cle_xor;
    std::string fname;
    std::string message;
    Texte fichier;

    std::cout << "Quel est le nom du fichier ? (pensez a ajouter texte/[...] sur cette version)" << std::endl;
    std::cin >> fname;

    std::cout << "Quelle est la taille du fichier en octets ?" << std::endl;
    std::cin >> taille;

    if (taille < 0) {
        std::cout << "Taille invalide !" << std::endl;
        return 1;
    }

    message = fichier.Lire(fname, taille);

    std::cout << "Choisissez ce que vous souhaitez faire : \n 1. Chiffrer \n 2. Dechiffrer" << std::endl;
    std::cin >> mode;

    switch (mode) {
    case 1:
        std::cout << "Quelle methode de chiffrement voulez-vous utiliser ? \n 1. Cesar \n 2. XOR \n 3. Cesar + XOR" << std::endl;
        std::cin >> met;

        switch (met) {
        case 1: {
            std::cout << "Quel decalage voulez-vous utiliser ?" << std::endl;
            std::cin >> cle;
            Cesar codage(cle);
            message = codage.Crypter(message);
            fichier.Ecrire(fname + ".crypte", message.size(), message);
            std::cout << "Fichier chiffre !" << std::endl;
            break;
        }
        case 2: {
            std::cout << "Quelle est la cle de chiffrement XOR ?" << std::endl;
            std::cin >> cle_xor;
            XOR codage(cle_xor);
            message = codage.Crypter(message);
            fichier.Ecrire(fname + ".crypte", message.size(), message);
            std::cout << "Fichier chiffre !" << std::endl;
            break;
        }
        case 3: {
            std::cout << "Quel decalage voulez-vous utiliser pour le chiffrement Cesar ?" << std::endl;
            std::cin >> cle;
            Cesar codage_cesar(cle);
            message = codage_cesar.Crypter(message);
            std::cout << "Quelle est la cle de chiffrement XOR ?" << std::endl;
            std::cin >> cle_xor;
            XOR codage_xor(cle_xor);
            message = codage_xor.Crypter(message);
            fichier.Ecrire(fname + ".crypte", message.size(), message);
            std::cout << "Fichier chiffre !" << std::endl;
            break;
        }
        default:
            std::cout << "Methode invalide !" << std::endl;
            break;
        }
        break;

    case 2:
        std::cout << "Quelle methode de dechiffrement voulez-vous utiliser ? \n 1. Cesar \n 2. XOR \n 3. Cesar + XOR" << std::endl;
        std::cin >> met;

        switch (met) {
        case 1: {
            std::cout << "Quel decalage a ete utilise ?" << std::endl;
            std::cin >> cle;
            Cesar codage(cle);
            message = codage.Decrypter(message);
            fichier.Ecrire(fname + ".decrypte", message.size(), message);
            std::cout << "Fichier dechiffre !" << std::endl;
            break;
        }
        case 2: {
            std::cout << "Quelle est la cle de dechiffrement XOR ?" << std::endl;
            std::cin >> cle_xor;
            XOR codage(cle_xor);
            message = codage.Crypter(message);
            fichier.Ecrire(fname + ".decrypte", message.size(), message);
            std::cout << "Fichier dechiffre !" << std::endl;
            break;
        }
        case 3: {
            std::cout << "Quel decalage a ete utilise pour le chiffrement Cesar ?" << std::endl;
            std::cin >> cle;
            std::cout << "Quelle est la cle de dechiffrement XOR ?" << std::endl;
            std::cin >> cle_xor;
            XOR codage_xor(cle_xor);
            message = codage_xor.Crypter(message);
            Cesar codage_cesar(cle);
            message = codage_cesar.Decrypter(message);
            fichier.Ecrire(fname + ".decrypte", message.size(), message);
            std::cout << "Fichier dechiffre !" << std::endl;
            break;
        }
        default:
            std::cout << "Methode invalide !" << std::endl;
            break;
        }
        break;

    default:
        std::cout << "Choix invalide" << std::endl;
        break;
    }
    return 0;
}
