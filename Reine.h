#pragma once

/**
 * Header de Reine.cpp
 *
 * @file Reine.h
 */

#if !defined Reine_h
#define Reine_h

#include "Fou.h"
#include "Tour.h"

class Reine : public Fou, public Tour
{
public:
    Reine(const int x, const int y, const bool c);
    Reine(const char colonne, const int ligne, const bool c);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

#endif // !defined Reine_h