#pragma once
#include "Piece.h"
class Tour : public virtual Piece
{
public:
    Tour(Couleur c, bool left);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();

protected:
    Tour(const int x, const int y, const Couleur c);
};

