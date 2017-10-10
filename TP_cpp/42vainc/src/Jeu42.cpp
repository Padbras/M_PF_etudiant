#include "Jeu42.hpp"

#include <cassert>
#include <sstream>

int Joueur::calculerScore() const
{
    // TODO accumulate
    int somme = 0;
    for (int n : _nombres)
        somme += n;
    return somme;
}

Jeu42::Jeu42(const std::string & nom1, const std::string & nom2)
{
    // TODO generate_n, inserter
    for (int n=8; n<18; n++)
        _nombresLibres.push_back(n);
    _joueur1 = {nom1, {2,3,4}};
    _joueur2 = {nom2, {5,6,7}};
    _ptrJoueurCourant = &_joueur1;
    _ptrJoueurSuivant = &_joueur2;
    _ptrVainqueur = nullptr;
}

void Jeu42::jouerCoup(int n1, int n2)
{
    liste_t & nCourants = _ptrJoueurCourant->_nombres;
    liste_t & nLibres = _nombresLibres;

    // verifie que n1 est dans la main courante
    // TODO find
    unsigned k1 = 0;
    for (; k1<nCourants.size(); k1++)
        if (nCourants[k1] == n1)
            break;
    if (k1 == nCourants.size())
        return;

    // verifie que n2 est dans les nombres libres
    // TODO find
    unsigned k2 = 0;
    for (; k2<nLibres.size(); k2++)
        if (nLibres[k2] == n2)
            break;
    if (k2 == nLibres.size())
        return;

    // echange n1 et n2 
    // TODO erase, insert
    nCourants[k1] = n2;
    nLibres[k2] = n1;

    // teste si le joueur gagne
    if (_ptrJoueurCourant->calculerScore() == 42)
        _ptrVainqueur = _ptrJoueurCourant;

    // passe au joueur suivant
    std::swap(_ptrJoueurCourant, _ptrJoueurSuivant);
}

bool Jeu42::enCours() const
{
    return _ptrVainqueur == nullptr;
}

const std::string & Jeu42::getVainqueur() const
{
    assert(not enCours());
    return _ptrVainqueur->_nom;
}

std::string Jeu42::getInfo() const
{
    std::stringstream ss;
    ss << _joueur1._nom << "=" << _joueur1.calculerScore() << "; ";
    ss << _joueur2._nom << "=" << _joueur2.calculerScore() << "; ";
    ss << "courant=" << _ptrJoueurCourant->_nom;
    return ss.str();
}

std::ostream & operator<<(std::ostream & os, const Jeu42 & jeu)
{
    os << "nombres libres : " << jeu._nombresLibres << std::endl;
    os << jeu._joueur1 << std::endl;
    os << jeu._joueur2 << std::endl;
    return os;
}

std::ostream & operator<<(std::ostream & os, const Joueur & joueur)
{
    os << joueur._nom << " : " << joueur._nombres;
    return os;
}

std::ostream & operator<<(std::ostream & os, const liste_t & liste)
{
    // TODO for_each, lambda
    for (int n : liste)
        os << n << ' '; 
    return os;
}

liste_t Jeu42::getNombresLibres() const
{
    return _nombresLibres;
}

const Joueur & Jeu42::getJoueur1() const
{
    return _joueur1;
}

const Joueur & Jeu42::getJoueur2() const
{
    return _joueur2;
}

