#pragma once

/**
 * Header de Partie.cpp
 *
 * @file Partie.h
 */

#if !defined Partie_h
#define Partie_h

#include "Echiquier.h"

class Partie
{
protected:
    Echiquier e;
    bool joueurActuel;
    int x;
    int y;

public:
    Partie();
    ~Partie();
    void jouerPartie();
    void verifCoordonnees();
    int JoueurActuelEnEchec();
};

#endif // !defined Partie_h