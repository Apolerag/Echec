#pragma once

/**
 * Header de Pion.cpp
 *
 * @file Pion.h
 */

#if !defined Pion_h
#define Pion_h

#include "Piece.h"
class Pion : public Piece
{
public:
    Pion();
    Pion(const int x, const int y, const bool c);
    Pion(const char colonne, const int ligne, const bool c);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

#endif // !defined Pion_h