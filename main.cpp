#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdio>

class Texte {
public:
    std::string texte;

    std::string Lire(const std::string& chemin, int taille_fichier) {
        FILE* fichier = fopen(chemin.c_str(), "rb");

        if (fichier == nullptr) {
            throw std::runtime_error("Impossible d'ouvrir : " + chemin);
        }

        fseek(fichier, 0, SEEK_SET);
        std::string contenu = "";

        for (int i = 0; i < taille_fichier; i++) {
            int caractere = fgetc(fichier);
            if (caractere == EOF) {
                break;
            }
            contenu += static_cast<char>(caractere);
        }

        fclose(fichier);
        return contenu;
    }

    void Ecrire(const std::string& chemin, int taille_fichier, const std::string& contenu) {
        FILE* fichier = fopen(chemin.c_str(), "wb");

        if (fichier == nullptr) {
            throw std::runtime_error("Impossible d'ouvrir : " + chemin);
        }

        for (int i = 0; i < taille_fichier && i < static_cast<int>(contenu.size()); i++) {
            fprintf(fichier, "%c", contenu[i]);
        }
        fclose(fichier);
    }
};

class Cesar {
public:
    int decalage;

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

class XOR {
public:
    std::string cle;
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

int main() {
    int mode, met, cle, taille;
    std::string cle_xor;
    std::string fname;
    std::string message;
    Texte fichier;

    std::cout << "Quel est le nom du fichier ?" << std::endl;
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
