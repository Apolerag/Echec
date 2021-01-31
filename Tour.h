#pragma once

/**
 * Header de Tour.cpp
 *
 * @file Tour.h
 */

#if !defined Tour_h
#define Tour_h

#include "Piece.h"

class Tour : public virtual Piece
{
public:
    Tour(const int x, const int y, const bool c);
    Tour(const char colonne, const int ligne, const bool c);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

#endif // !defined Tour_h