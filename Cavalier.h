#pragma once

/**
 * Header de Cavalier.cpp
 *
 * @file Cavalier.h
 */

#include "Piece.h"
class Cavalier : public Piece
{
public:
    Cavalier(const int x, const int y, const bool c);
    Cavalier(const char colonne, const int ligne, const bool c);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

