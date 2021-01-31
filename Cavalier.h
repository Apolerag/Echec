#pragma once

/**
 * Header de Cavalier.cpp
 *
 * @file Cavalier.h
 */

#if !defined Cavalier_h
#define Cavalier_h

#include "Piece.h"
class Cavalier : public Piece
{
public:
    Cavalier(const int x, const int y, const bool c);
    Cavalier(const char colonne, const int ligne, const bool c);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

#endif // !defined Cavalier_h