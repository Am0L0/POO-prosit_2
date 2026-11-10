#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

int main(){
    int mode, met, cle;
    std::string fname;

    std::cout << "Quel est le nom du fichier ?" << std::endl;
    std::cin >> fname;
    std::cout << "Choisissez ce que vous souhaitez faire : \n 1. Chiffrer \n 2. Dechiffrer" << std::endl;
    std::cin >> mode;

    switch (mode)
    {
    case 1:
        /*
        Chiffrement
        */
        std::cout << "Quel methode de chiffrement voulez vous utilser ? \n 1. César \n 2. XOR \n 3. César + XOR" << std::endl;
        std::cin >> met;

        switch (met)
        {
        case 1:
            // Methode CESAR
            break;
        
        case 2:
            // Methode XOR
            break;

        case 3: 
            // Methode CESAR + XOR
            break;

        }
        break;
    
    case 2:
        /*
        Dechiffrement
        */
        std::cout << "Quel methode de dechiffrement voulez vous utilser ? \n 1. César \n 2. XOR \n 3. César + XOR" << std::endl;
        std::cin >> met;

        std::fstream fichier(fname, std::ios::in);
        if (fichier) {

            std::string ligne;
            while (std::getline(fichier, ligne)){
                switch (met)
                {
                case 1:
                    // Methode CESAR
                    std::cout << "Quel cle voulez vous utiliser (int)" << std::endl;
                    std::cin >> cle;
                    break;
                
                case 2:
                    // Methode XOR
                    std::cout << "Quel cle voulez vous utiliser (int)" << std::endl;
                    std::cin >> cle;
                    break;

                case 3: 
                    // Methode CESAR + XOR
                    std::cout << "Quel cle CESAR voulez vous utiliser (int)" << std::endl;
                    std::cin >> cle;
                    break;
                }
                fichier.close();
                break;
        }}else {
            std::cerr << "Erreur a l'ouverture du fichier" << std::endl;
            }
    }

    return 0;
}