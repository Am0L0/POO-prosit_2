#include <iostream>
#include <math.h>
#include <fstream>
#include <string>


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
    char alphabet_clair[27];
    char alphabet_crypte[27];

    void initialiserAlphabets() {
        for (int i = 0; i < 26; i++) {
            alphabet_clair[i] = static_cast<char>('A' + i);
            alphabet_crypte[i] = static_cast<char>('A' + (i + decalage) % 26);
        }

        alphabet_clair[26] = '\0';
        alphabet_crypte[26] = '\0';
    }

    Cesar(int nouveau_decalage) {
        decalage = ((nouveau_decalage % 26) + 26) % 26;
        initialiserAlphabets();
    }

    Cesar() {
        decalage = 1;
        initialiserAlphabets();
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




int main() {
    int mode, met, cle, taille;
    std::string fname;
    std::string message;
    std::string continue;
    Texte fichier;

    std::cout << "Quel est le nom du fichier ?" << std::endl;
    std::cin >> fname;

    std::cout << "Quelle est la taille du fichier en octets ?" << std::endl;
    std::cin >> taille;

    message = fichier.Lire(fname, taille);

    std::cout << "Choisissez ce que vous souhaitez faire : \n 1. Chiffrer \n 2. Dechiffrer" << std::endl;
    std::cin >> mode;

    switch (mode)
    {
    case 1:
        // Chiffrement
        std::cout << "Quel methode de chiffrement voulez vous utiliser ? \n 1. Cesar \n 2. XOR \n 3. Cesar + XOR" << std::endl;
        std::cin >> met;

        switch (met)
        {
        case 1:
        {
            // Methode CESAR
            std::cout << "Quel decalage voulez vous utiliser ?" << std::endl;
            std::cin >> cle;

            Cesar codage(cle);
            message = codage.Crypter(message);

            fichier.Ecrire(fname + ".crypte", message.size(), message);

            std::cout << "Fichier chiffre !" << std::endl;
            break;
        }

        case 2:
            // Methode XOR
            break;

        case 3:
            // Methode CESAR + XOR
            break;
        }
        break;

    case 2:
        // Dechiffrement
        std::cout << "Quel methode de dechiffrement voulez vous utiliser ? \n 1. Cesar \n 2. XOR \n 3. Cesar + XOR" << std::endl;
        std::cin >> met;

        switch (met)
        {
        case 1:
        {
            // Methode CESAR
            std::cout << "Quel decalage a ete utilise ?" << std::endl;
            std::cin >> cle;

            Cesar codage(cle);
            message = codage.Decrypter(message);

            fichier.Ecrire(fname + ".decrypte", message.size(), message);

            std::cout << "Fichier dechiffre !" << std::endl;
            break;
        }

        case 2:
            // Methode XOR
            break;

        case 3:
            // Methode CESAR + XOR
            break;
        }
        break;

    default:
        std::cout << "Choix invalide" << std::endl;
        break;
    }

    return 0;
}
