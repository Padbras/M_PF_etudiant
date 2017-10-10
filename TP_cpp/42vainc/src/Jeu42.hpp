#ifndef _JEU42_HPP_
#define _JEU42_HPP_

#include <iostream>

// TODO remplacer vector par set
#include <vector>
typedef std::vector<int> liste_t;

struct Joueur
{
    std::string _nom;
    liste_t _nombres;
    int calculerScore() const;
};

class Jeu42 
{
    private:
        liste_t _nombresLibres;
        Joueur _joueur1;
        Joueur _joueur2;

        Joueur * _ptrJoueurCourant;
        Joueur * _ptrJoueurSuivant;
        Joueur * _ptrVainqueur;

    public:
        Jeu42(const std::string & nom1, const std::string & nom2);
        void jouerCoup(int n1, int n2);
        bool enCours() const;

        liste_t getNombresLibres() const;
        const Joueur & getJoueur1() const;
        const Joueur & getJoueur2() const;

        const std::string & getVainqueur() const;
        std::string getInfo() const;

        friend std::ostream & operator<<(std::ostream & os, const Jeu42 & jeu);
};

std::ostream & operator<<(std::ostream & os, const Jeu42 & jeu);
std::ostream & operator<<(std::ostream & os, const Joueur & joueur);
std::ostream & operator<<(std::ostream & os, const liste_t & liste);

#endif

