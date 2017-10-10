
#include "Jeu42.hpp"

#include <iostream>

const std::string accueilJeu42 
= "Bienvenue dans le jeu du '42 vainc'. Vous êtes 2 joueurs. Chaque joueur a "\
   "une\nmain de 3 nombres. À tour de rôle, chaque joueur échange un de ses "\
   "nombres avec\nun nombre libre. Le premier joueur dont la somme des "\
   "nombres fait 42 gagne."; 

int main()
{
    std::cout << std::endl << accueilJeu42 << std::endl;

    Jeu42 jeu("Joueur 1", "Joueur 2");

    while (jeu.enCours())
    {
        std::cout << std::endl << jeu;
        std::cout << jeu.getInfo() << std::endl; 
        std::cout << "Coup (<nombre du joueur> <nombre libre>) : ";
        int n1, n2;
        std::cin >> n1 >> n2;
        jeu.jouerCoup(n1, n2);
    }

    std::cout << std::endl << "Fin du jeu : " << jeu.getVainqueur() 
              << " a gagné." << std::endl;

    return 0;
}

