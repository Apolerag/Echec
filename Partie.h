#pragma once

/**
 * Header de Partie.cpp
 *
 * @file Partie.h
 */

#if !defined Partie_h
#define Partie_h

#include "Echiquier.h"
#include <vector>

class Partie
{
protected:
    Echiquier m_e;
    bool m_joueurActuel;
    vector<Piece*> m_PiecesBlanche;
    vector<Piece*> m_PiecesNoires;
    Piece* m_RoiBlanc;
    Piece* m_RoiNoir;

public:
    Partie();
    ~Partie();

    /**
    * Le deroulement de la partie
    */
    void jouerPartie();

    /**
    * Recuperer les coordonnees de l'utilisateur
    * @param x la colonne
    * @param y la ligne
    */
    void getCoordonnees(int& x, int& y);

    /**
    * Verifie s'il y a echec
    * @return 0 si pas echec, 1 si echec, 2 si mat
    */
    int Echec();


    /**
    * Verifie s'il y a pat
    * @return true si pat, sinon false
    */
    bool Pat();
};

#endif // !defined Partie_h