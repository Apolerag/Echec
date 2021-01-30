#pragma once
#include "Piece.h"

class Fou : public virtual Piece
{
public:
    Fou(Couleur c, bool left);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();

protected:
    Fou(const int x, const int y, const Couleur c);
};

