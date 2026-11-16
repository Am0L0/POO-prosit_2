#ifndef TEXTE_H
#define TEXTE_H

#include <cstdio>
#include <string>
#include <iostream>

class Texte {
public:
    static std::string Lire(const std::string& chemin, int taille_fichier) {
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

    static void Ecrire(const std::string& chemin, int taille_fichier, const std::string& contenu) {
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

#endif