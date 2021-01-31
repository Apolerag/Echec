#pragma once

/**
 * Header de Fou.cpp
 *
 * @file Fou.h
 */

#if !defined Fou_h
#define Fou_h

#include "Piece.h"

class Fou : public virtual Piece
{
public:
    Fou(const int x, const int y, const bool c);
    Fou(const char colonne, const int ligne, const bool c);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

#endif // !defined Fou_h