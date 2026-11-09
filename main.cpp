#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

int main(){
    int mode, met;
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
    }

    return 0;
}