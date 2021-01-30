#pragma once
#include "Piece.h"

class Fou : public Piece
{
public:
    Fou(Couleur c, bool left);
    bool mouvementValide(Echiquier& e, int x, int y);
    char codePiece();
};

